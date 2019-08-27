//Conflicting method: BIOS::LCD::Print$5
//Conflicting method: BIOS::LCD::Print$5
// Automatically generated by exports.js

uint32_t GetProcAddress(char* symbol)
{
  uint32_t hash = 5381;
  uint8_t c;
  while ((c = *symbol++) != 0)
    hash = hash*37 + c;

  switch (hash & 0x0000ffff)
  {
    case 0x000046de: return (uint32_t)sprintf;
    case 0x00002057: return (uint32_t)vsprintf;
    case 0x00002023: return (uint32_t)static_cast<void(*)(CRect const&, unsigned long, unsigned long)>(GUI::Background); 
    case 0x00007eba: return (uint32_t)static_cast<void(*)(CRect const&, unsigned short)>(GUI::Window); 
    case 0x00009955: return (uint32_t)static_cast<char*(*)()>(BIOS::OS::GetArgument); 
    case 0x00003cf9: return (uint32_t)static_cast<bool(*)()>(BIOS::OS::HasArgument); 
    case 0x0000daaa: return (uint32_t)static_cast<void(*)(char*)>(BIOS::OS::SetArgument); 
    case 0x00009001: return (uint32_t)static_cast<void(*)(unsigned long)>(BIOS::OS::EnableInterrupts); 
    case 0x00008cd4: return (uint32_t)static_cast<uint32_t(*)()>(BIOS::OS::DisableInterrupts); 
    case 0x000007cc: return (uint32_t)BIOS::OS::GetInterruptVector;
    case 0x00003cbf: return (uint32_t)static_cast<void(*)(BIOS::OS::EInterruptVector, void (*)())>(BIOS::OS::SetInterruptVector); 
#if defined(DS203) || defined(DS213)
    case 0x00005afd: return (uint32_t)static_cast<int(*)()>(BIOS::ADC::GetPointer); 
    case 0x00006f3a: return (uint32_t)static_cast<void(*)(BIOS::ADC::EInput, BIOS::ADC::ECouple, BIOS::ADC::EResolution, int)>(BIOS::ADC::ConfigureInput); 
    case 0x00009bd3: return (uint32_t)static_cast<void(*)(int, int, BIOS::ADC::ETriggerType, BIOS::ADC::EInput)>(BIOS::ADC::ConfigureTrigger); 
    case 0x0000e2eb: return (uint32_t)static_cast<void(*)(float)>(BIOS::ADC::ConfigureTimebase); 
    case 0x0000c656: return (uint32_t)BIOS::ADC::Get;
    case 0x00009593: return (uint32_t)static_cast<void(*)()>(BIOS::ADC::Init); 
    case 0x0000fafd: return (uint32_t)static_cast<bool(*)()>(BIOS::ADC::Ready); 
    case 0x00004d2c: return (uint32_t)static_cast<void(*)(bool)>(BIOS::ADC::Enable); 
    case 0x000083ed: return (uint32_t)static_cast<bool(*)()>(BIOS::ADC::Enabled); 
    case 0x0000946f: return (uint32_t)static_cast<void(*)()>(BIOS::ADC::Restart); 
    case 0x00006300: return (uint32_t)BIOS::ADC::GetState;
    case 0x00004740: return (uint32_t)static_cast<int(*)()>(BIOS::DAC::GetFrequency); 
    case 0x0000fdaf: return (uint32_t)static_cast<void(*)(int)>(BIOS::DAC::SetFrequency); 
    case 0x0000fca4: return (uint32_t)static_cast<int(*)()>(BIOS::DAC::GetDuty); 
    case 0x0000df23: return (uint32_t)static_cast<void(*)(int)>(BIOS::DAC::SetDuty); 
    case 0x0000c8c0: return (uint32_t)static_cast<void(*)(unsigned short*, int)>(BIOS::DAC::SetWave); 
#endif
    case 0x0000ffe4: return (uint32_t)static_cast<void(*)(char const*, ...)>(BIOS::DBG::Print); 
    case 0x0000758f: return (uint32_t)static_cast<ui32(*)()>(BIOS::FAT::GetFileSize); 
    case 0x000008ad: return (uint32_t)static_cast<void*(*)()>(BIOS::FAT::GetSharedBuffer); 
    case 0x0000a6b5: return (uint32_t)static_cast<void(*)(void*)>(BIOS::FAT::SetSharedBuffer); 
    case 0x00004f66: return (uint32_t)static_cast<BIOS::FAT::EResult(*)()>(BIOS::FAT::Init); 
    case 0x00009148: return (uint32_t)static_cast<BIOS::FAT::EResult(*)(char const*, unsigned char)>(BIOS::FAT::Open); 
    case 0x000044e4: return (uint32_t)static_cast<BIOS::FAT::EResult(*)(unsigned char*)>(BIOS::FAT::Read); 
    case 0x0000b3a1: return (uint32_t)static_cast<BIOS::FAT::EResult(*)(unsigned long)>(BIOS::FAT::Seek); 
    case 0x0000f0a8: return (uint32_t)static_cast<BIOS::FAT::EResult(*)(int)>(BIOS::FAT::Close); 
    case 0x0000f0b5: return (uint32_t)static_cast<BIOS::FAT::EResult(*)()>(BIOS::FAT::Close); 
    case 0x0000c6c0: return (uint32_t)static_cast<BIOS::FAT::EResult(*)(unsigned char*)>(BIOS::FAT::Write); 
    case 0x000034ef: return (uint32_t)static_cast<BIOS::FAT::EResult(*)(char*)>(BIOS::FAT::OpenDir); 
    case 0x0000deaf: return (uint32_t)static_cast<BIOS::FAT::EResult(*)(BIOS::FAT::TFindFile*)>(BIOS::FAT::FindNext); 
    case 0x0000a964: return (uint32_t)static_cast<bool(*)()>(BIOS::KEY::KeyPressed); 
    case 0x00000b63: return (uint32_t)static_cast<BIOS::KEY::EKey(*)()>(BIOS::KEY::GetKey); 
    case 0x00008f74: return (uint32_t)static_cast<void(*)(unsigned short*, int)>(BIOS::LCD::BufferRead); 
    case 0x00000cc5: return (uint32_t)static_cast<uint16_t(*)()>(BIOS::LCD::BufferRead); 
    case 0x00000430: return (uint32_t)static_cast<void(*)(CRect const&)>(BIOS::LCD::BufferBegin); 
    case 0x0000d8f4: return (uint32_t)static_cast<void(*)(unsigned short*, int)>(BIOS::LCD::BufferWrite); 
    case 0x0000f243: return (uint32_t)static_cast<void(*)(unsigned short)>(BIOS::LCD::BufferWrite); 
    case 0x0000ff2f: return (uint32_t)static_cast<void(*)(CRect const&, unsigned short)>(BIOS::LCD::Bar); 
    case 0x0000e34c: return (uint32_t)static_cast<void(*)(int, int, int, int, unsigned short)>(BIOS::LCD::Bar); 
    case 0x00003e5e: return (uint32_t)static_cast<int(*)(int, int, unsigned short, unsigned short, char const*)>(BIOS::LCD::Draw); 
    case 0x00005994: return (uint32_t)static_cast<void(*)(unsigned short)>(BIOS::LCD::Clear); 
    case 0x0000b8c2: return (uint32_t)static_cast<int(*)(int, int, unsigned short, unsigned short, char const*)>(BIOS::LCD::Print); 
    case 0x00009d4b: return (uint32_t)static_cast<int(*)(int, int, unsigned short, unsigned short, char*)>(BIOS::LCD::Print); 
    case 0x000080db: return (uint32_t)static_cast<int(*)(int, int, unsigned short, unsigned short, char)>(BIOS::LCD::Print); 
    case 0x00008063: return (uint32_t)static_cast<int(*)(int, int, unsigned short, unsigned short, char const*, ...)>(BIOS::LCD::Printf); 
    case 0x00002206: return (uint32_t)static_cast<void(*)(int, int, int, int, unsigned int)>(BIOS::LCD::Shadow); 
    case 0x00000509: return (uint32_t)static_cast<void(*)(int, int, int, int, unsigned short const*, int)>(BIOS::LCD::Pattern); 
    case 0x000085ac: return (uint32_t)static_cast<uint16_t(*)(int, int)>(BIOS::LCD::GetPixel); 
    case 0x0000698f: return (uint32_t)static_cast<void(*)(CPoint const&, unsigned short)>(BIOS::LCD::PutPixel); 
    case 0x0000a105: return (uint32_t)static_cast<void(*)(int, int, unsigned short)>(BIOS::LCD::PutPixel); 
    case 0x00007604: return (uint32_t)static_cast<void(*)()>(BIOS::LCD::BufferEnd); 
    case 0x0000850d: return (uint32_t)static_cast<void(*)(CRect const&, unsigned short)>(BIOS::LCD::Rectangle); 
    case 0x0000f4c2: return (uint32_t)static_cast<void(*)(CRect const&, unsigned short)>(BIOS::LCD::RoundRect); 
    case 0x0000ba0f: return (uint32_t)static_cast<void(*)(int, int, int, int, unsigned short)>(BIOS::LCD::RoundRect); 
    case 0x0000c701: return (uint32_t)static_cast<void(*)(int)>(BIOS::SYS::Beep); 
    case 0x00005757: return (uint32_t)static_cast<void(*)(int)>(BIOS::SYS::DelayMs); 
    case 0x00003867: return (uint32_t)static_cast<int(*)(unsigned long)>(BIOS::SYS::Execute); 
    case 0x000080a4: return (uint32_t)static_cast<uint32_t(*)()>(BIOS::SYS::GetTick); 
    case 0x000082e8: return (uint32_t)static_cast<void(*)(void*, void*, void*, void*, void (**)(), void (**)(), void (**)())>(BIOS::USB::Initialize); 
    case 0x0000148c: return (uint32_t)static_cast<void(*)()>(BIOS::USB::InitializeMass); 
    case 0x00005b72: return (uint32_t)static_cast<void(*)(int)>(BIOS::USB::InitializeFinish); 
    case 0x0000c932: return (uint32_t)static_cast<void(*)()>(BIOS::USB::InitializeSerial); 
    case 0x0000c9d6: return (uint32_t)static_cast<void(*)()>(BIOS::USB::Enable); 
    case 0x000029c0: return (uint32_t)static_cast<void(*)()>(BIOS::USB::Disable); 
#if defined(LA104)
    case 0x000005e5: return (uint32_t)static_cast<int(*)(BIOS::GPIO::EPin)>(BIOS::GPIO::AnalogRead); 
    case 0x00006d86: return (uint32_t)static_cast<void(*)(BIOS::GPIO::EPin, int)>(BIOS::GPIO::AnalogWrite); 
    case 0x00005476: return (uint32_t)static_cast<bool(*)(BIOS::GPIO::EPin)>(BIOS::GPIO::DigitalRead); 
    case 0x00007bbc: return (uint32_t)static_cast<void(*)(BIOS::GPIO::EPin, bool)>(BIOS::GPIO::DigitalWrite); 
    case 0x0000916d: return (uint32_t)static_cast<bool(*)(unsigned char, unsigned char)>(BIOS::GPIO::I2C::RequestFrom); 
    case 0x0000089b: return (uint32_t)static_cast<bool(*)()>(BIOS::GPIO::I2C::EndTransmission); 
    case 0x0000e295: return (uint32_t)static_cast<bool(*)(unsigned char)>(BIOS::GPIO::I2C::BeginTransmission); 
    case 0x0000f648: return (uint32_t)static_cast<uint8_t(*)()>(BIOS::GPIO::I2C::Read); 
    case 0x00009ffe: return (uint32_t)static_cast<bool(*)(unsigned char)>(BIOS::GPIO::I2C::Write); 
    case 0x00008ee3: return (uint32_t)static_cast<uint8_t(*)()>(BIOS::GPIO::UART::Read); 
    case 0x0000ee78: return (uint32_t)static_cast<void(*)(int, BIOS::GPIO::UART::EConfig)>(BIOS::GPIO::UART::Setup); 
    case 0x0000ae65: return (uint32_t)static_cast<void(*)(unsigned char)>(BIOS::GPIO::UART::Write); 
    case 0x0000e98d: return (uint32_t)static_cast<bool(*)()>(BIOS::GPIO::UART::Available); 
    case 0x0000ddad: return (uint32_t)static_cast<void(*)(BIOS::GPIO::EPin, BIOS::GPIO::EMode)>(BIOS::GPIO::PinMode); 
#endif
    case 0x00000b9e: return (uint32_t)static_cast<void(*)()>(BIOS::MEMORY::LinearStart); 
    case 0x0000493a: return (uint32_t)static_cast<bool(*)()>(BIOS::MEMORY::LinearFinish); 
    case 0x0000cbce: return (uint32_t)static_cast<bool(*)(unsigned long, unsigned char*, int)>(BIOS::MEMORY::LinearProgram); 
    case 0x0000807e: return (uint32_t)static_cast<void*(*)()>(BIOS::MEMORY::GetSharedBuffer); 
    case 0x0000f7ea: return (uint32_t)static_cast<void(*)(void*)>(BIOS::MEMORY::SetSharedBuffer); 
    case 0x0000ed83: return (uint32_t)BIOS::PRIVATE::GetCharRom;
    default: return 0;
  }
}

