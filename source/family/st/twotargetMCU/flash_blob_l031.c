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

static const uint32_t STM32L0xx_32_flash_prog_blob[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0xd0012a01, 0xd1172a02, 0x6981484a, 0x0212220f, 0x61814311, 0x60c14948, 0x60c14948, 0x61014948,
    0x61014948, 0x02c069c0, 0x4848d406, 0x60014946, 0x60412106, 0x60814946, 0x47702000, 0xd0012801,
    0xd1082802, 0x6841483b, 0x43112202, 0x68416041, 0x43112201, 0x20006041, 0xb5704770, 0x20014935,
    0x06c0684a, 0x431a1483, 0x684a604a, 0x43222408, 0x4e38604a, 0x60052500, 0x07d2698a, 0x3080d1fc,
    0xd3f842b0, 0x43986848, 0x68486048, 0x604843a0, 0xbd702000, 0x4927b530, 0x154c684a, 0x604a4322,
    0x2508684a, 0x604a432a, 0x60022200, 0x4a27482a, 0x6010e000, 0x07db698b, 0x6848d1fb, 0x604843a0,
    0x43a86848, 0x20006048, 0x2001bd30, 0xb5f04770, 0x23004c18, 0x26081525, 0x0989313f, 0xe024468c,
    0x43296861, 0x68616061, 0x60614331, 0xca802140, 0x1f09c080, 0xd1fa2900, 0x69a74917, 0xd00207ff,
    0x60394f12, 0x69a1e7f9, 0x0f090509, 0x69a0d006, 0x0209210f, 0x61a04308, 0xbdf02001, 0x43a96861,
    0x68616061, 0x606143b1, 0x459c1c5b, 0x2000d8d8, 0x0000bdf0, 0x40022000, 0x89abcdef, 0x02030405,
    0x8c9daebf, 0x13141516, 0x00005555, 0x40003000, 0x00000fff, 0x08008000, 0x0000aaaa, 0x00000000
};

// Start address of flash
static const uint32_t flash_start = 0x08000000;
// Size of flash
static const uint32_t flash_size = 0x00008000;

/**
* List of start and size for each size of flash sector - even indexes are start, odd are size
* The size will apply to all sectors between the listed address and the next address
* in the list.
* The last pair in the list will have sectors starting at that address and ending
* at address flash_start + flash_size.
*/
static const sector_info_t sectors_info[] = {
    {0x08000000, 0x00000080},
};

static const program_target_t flash = {
    0x20000021, // Init
    0x2000005d, // UnInit
    0x2000007b, // EraseChip
    0x200000b5, // EraseSector
    0x200000ef, // ProgramPage
    0x0, // Verify

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x20000001,
        0x2000017c,
        0x20000400
    },

    0x20000000 + 0x00000A00,  // mem buffer location
    0x20000000,               // location to write prog_blob in target RAM
    sizeof(STM32L0xx_32_flash_prog_blob),   // prog_blob size
    STM32L0xx_32_flash_prog_blob,           // address of prog_blob
    0x00000400       // ram_to_flash_bytes_to_be_written
};


