#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/IoLib.h>
#include "WinMRegisters.h"

#define WINM_DART_BASE 0x2FA808000ULL

#define DART_PARAMS1 0x00
#define DART_PARAMS1_PAGE_SHIFT 24
#define DART_PARAMS2 0x04
#define DART_T8020_STREAM_COMMAND 0x20
#define DART_T8020_TTBR 0x200

EFI_STATUS
EFIAPI
WinMDartDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  UINT32 params1;
  UINT32 params2;
  UINT32 page_shift;

  params1 = MmioRead32 (WINM_DART_BASE + DART_PARAMS1);
  params2 = MmioRead32 (WINM_DART_BASE + DART_PARAMS2);
  page_shift = (params1 >> DART_PARAMS1_PAGE_SHIFT) & 0xFU;

  Print (L"WinM: DART base=0x%lx params1=0x%x params2=0x%x page_shift=%u\\n",
         WINM_DART_BASE, params1, params2, page_shift);
  return EFI_SUCCESS;
}
