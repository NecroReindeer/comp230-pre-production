#pragma once

#if defined DLL_EXPORT
#define PEG_API __declspec(dllexport)
#else
#define PEG_API __declspec(dllimport)
#endif

extern "C"
{
  
}