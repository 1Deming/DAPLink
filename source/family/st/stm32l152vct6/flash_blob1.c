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
 
static const uint32_t STM32L1xx_256_flash_prog_blob[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x4603b510, 0xd0022a01, 0xd1222a02, 0xbf00e000, 0x68004872, 0x6070f440, 0x60204c70, 0x4c6f4870,
    0x60203c0c, 0x6020486f, 0x1d24486f, 0x486f6020, 0x486a6020, 0x68001d00, 0x1f80f410, 0xf245d108,
    0x4c6b5055, 0x20066020, 0xf6406060, 0x60a070ff, 0xbf00bf00, 0xbd102000, 0x29014601, 0x2902d002,
    0xe000d10f, 0x485dbf00, 0x68003814, 0x0002f040, 0x3a144a5a, 0x46106010, 0xf0406800, 0x60100001,
    0xbf00bf00, 0x47702000, 0x48544601, 0x68003814, 0x7000f440, 0x3a144a51, 0x46106010, 0xf0406800,
    0x60100008, 0x60082000, 0xf64ae003, 0x4a5020aa, 0x484a6010, 0xf0106800, 0xd1f60f01, 0x38144847,
    0xf4206800, 0x4a457000, 0x60103a14, 0x68004610, 0x0008f020, 0x20006010, 0x46034770, 0x47702001,
    0x4603b530, 0xf1012480, 0xf02000ff, 0x483b01ff, 0x68003814, 0x6080f440, 0x3d144d38, 0x46286028,
    0xf0406800, 0x60280008, 0xe005bf00, 0x60186810, 0x1d121d1b, 0x1f241f09, 0x2c00b109, 0xe003d1f6,
    0x20aaf64a, 0x60284d32, 0x6800482c, 0x0f01f010, 0x482ad1f6, 0xf4106800, 0xd0076f70, 0x68004827,
    0x6070f440, 0x60284d25, 0xbd302001, 0x38144823, 0xf4206800, 0x4d216080, 0x60283d14, 0x68004628,
    0x0008f020, 0x46286028, 0xf4406800, 0x60286080, 0x68004628, 0x0008f040, 0x24806028, 0x6810e005,
    0x1d1b6018, 0x1f091d12, 0xb1091f24, 0xd1f62c00, 0xf64ae003, 0x4d1620aa, 0x48106028, 0xf0106800,
    0xd1f60f01, 0x6800480d, 0x6f70f410, 0x480bd007, 0xf4406800, 0x4d096070, 0x20016028, 0x4807e7c5,
    0x68003814, 0x6080f420, 0x3d144d04, 0x46286028, 0xf0206800, 0x60280008, 0xe7b62000, 0x40023c18,
    0x89abcdef, 0x02030405, 0x8c9daebf, 0x13141516, 0x40003000, 0x00000000
};

// Start address of flash
static const uint32_t flash_start = 0x08000000;
// Size of flash
static const uint32_t flash_size = 0x00040000;

/**
* List of start and size for each size of flash sector - even indexes are start, odd are size
* The size will apply to all sectors between the listed address and the next address
* in the list.
* The last pair in the list will have sectors starting at that address and ending
* at address flash_start + flash_size.
*/
static const sector_info_t sectors_info[] = {
    {0x08000000, 0x00000100},
};

static const program_target_t flash = {
    0x20000021, // Init
    0x20000079, // UnInit
    0x20000079, // EraseChip
    0x200000a9, // EraseSector
    0x20000101, // ProgramPage
    0x20000021, // Verify

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x20000001,
        0x20000214,
        0x20000500
    },

    0x20000000 + 0x00000A00,  // mem buffer location
    0x20000000,               // location to write prog_blob in target RAM
    sizeof(STM32L1xx_256_flash_prog_blob),   // prog_blob size
    STM32L1xx_256_flash_prog_blob,           // address of prog_blob
    0x00000400       // ram_to_flash_bytes_to_be_written
};


