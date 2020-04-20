/* Flash OS Routines (Automagically Generated)
 * Copyright (c) 2009-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

static const uint32_t STM32F7x_1024_flash_prog_blob[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x8f4ff3bf, 0x02c04770, 0x28400dc0, 0x0980d302, 0x47701d00, 0xd3022820, 0x1cc00940, 0x08c04770,
    0x48494770, 0x60414947, 0x60414948, 0x60012100, 0x22f068c1, 0x60c14311, 0x06806940, 0x4845d406,
    0x60014943, 0x60412106, 0x60814943, 0x47702000, 0x6901483d, 0x43110542, 0x20006101, 0xb5104770,
    0x69014839, 0x43212404, 0x69016101, 0x431103a2, 0x493a6101, 0xe0004a37, 0x68c36011, 0xd4fb03db,
    0x43a16901, 0x20006101, 0xb530bd10, 0xffbbf7ff, 0x68ca492d, 0x431a23f0, 0x240260ca, 0x690a610c,
    0x0e0006c0, 0x610a4302, 0x03e26908, 0x61084310, 0x8f4ff3bf, 0x4a274829, 0x6010e000, 0x03ed68cd,
    0x6908d4fb, 0x610843a0, 0x060068c8, 0xd0030f00, 0x431868c8, 0x200160c8, 0xb5f0bd30, 0x1cc94c1a,
    0x68e50889, 0x23f00089, 0x60e5431d, 0x61232300, 0x06ff2701, 0xe0214d19, 0x4e196923, 0x61234333,
    0x0af602c6, 0x681319f6, 0xf3bf6033, 0x4e118f4f, 0x6035e000, 0x03db68e3, 0x6923d4fb, 0x005b085b,
    0x68e36123, 0x0f1b061b, 0x68e0d005, 0x430821f0, 0x200160e0, 0x1d00bdf0, 0x1d121f09, 0xd1db2900,
    0xbdf02000, 0x45670123, 0x40023c00, 0xcdef89ab, 0x00005555, 0x40003000, 0x00000fff, 0x0000aaaa,
    0x00000201, 0x00000000
};

// Start address of flash
static const uint32_t flash_start = 0x08000000;
// Size of flash
static const uint32_t flash_size = 0x00100000;

/**
* List of start and size for each size of flash sector - even indexes are start, odd are size
* The size will apply to all sectors between the listed address and the next address
* in the list.
* The last pair in the list will have sectors starting at that address and ending
* at address flash_start + flash_size.
*/
static const sector_info_t sectors_info[] = {
   { 0x08000000, 0x00008000},
   { 0x08020000, 0x00020000},
   { 0x08040000, 0x00040000},
};

static const program_target_t flash = {
    0x20000043, // Init
    0x20000071, // UnInit
    0x2000007f, // EraseChip
    0x200000ab, // EraseSector
    0x200000fb, // ProgramPage
    0x0, // Verify

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x20000001,
        0x20000184,
        0x20000400
    },

    0x20000000 + 0x00000A00,  // mem buffer location
    0x20000000,               // location to write prog_blob in target RAM
    sizeof(STM32F7x_1024_flash_prog_blob),   // prog_blob size
    STM32F7x_1024_flash_prog_blob,           // address of prog_blob
    0x00000400       // ram_to_flash_bytes_to_be_written
};


