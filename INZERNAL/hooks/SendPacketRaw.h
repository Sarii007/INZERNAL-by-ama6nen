#pragma once
#include <core/globals.h>
#include <hooks/Update.h>
#include <sdk/sdk.h>
#include <string>

class SendPacketRawHook {
   public:
    static void Execute(int type, GameUpdatePacket* packet, int size, void* packetsender, ENetPeer* peer, int flag) {
        static auto orig = decltype(&hooks::SendPacketRaw)(hookmgr->orig(sig::sendpacketraw));

        if (opt::cheat::block_sendpacketraw)
            return;

        if (packet->type == PACKET_APP_INTEGRITY_FAIL) {
            utils::printc("95", "Was going to send a packet about app integrity failure, but we blocked it.");
            return;
        }

        if (packet->type == PACKET_CALL_FUNCTION) {
            if (logging::enabled && logging::console & logging::callfuncspr) {
                variantlist_t varlist{};

                if (varlist.serialize_from_mem(utils::get_extended(packet))) {
                    auto content = varlist.print();
                    if (content.size() < 4096)
                    utils::printc("95", "[outgoing varlist]\t%s", content.c_str());
                }
            }
        }
        if (logging::enabled && logging::console & logging::sendpacketraw)
            printf("sending raw packet: %d [%s]\n", packet->type, gt::get_type_string(packet->type).c_str());

        if (packet->type == 0 && packet->flags & 4) {
            auto player = sdk::GetGameLogic()->GetLocalPlayer();
            if (player)
                UpdateManager::OnJoinedWorld(player);
        }

        if (packet->velocity_x == 1000.f || packet->type == PACKET_PING_REPLY) {
            GameUpdatePacket pk{ 0 };
            pk.type = PACKET_PING_REPLY;
            pk.ping_hash = packet->ping_hash; // HashString of ping request int data field
            pk.int_data = packet->int_data;   // tick count (speedhack)
            pk.pos_x = 64.f;                  // punch range in pixels
            pk.pos_y = 64.f;                  // build range in pixels
            pk.velocity_x = 1000.f;           //gravity
            pk.velocity_y = 250.f;            // movement speed

            void* PacketSender = nullptr;
            orig(NET_MESSAGE_GAME_PACKET, &pk, 56, PacketSender, peer, flag);
            return;
        }

        orig(type, packet, size, packetsender, peer, flag);
    }
};