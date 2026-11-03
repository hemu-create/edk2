#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/IoLib.h>
#include "WinMRegisters.h"

EFI_STATUS
EFIAPI
WinMDartDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  UINT32 params1;
  UINT32 params2;
  UINT32 tcr;
  UINT32 page_shift;

  params1 = MmioRead32 (WINM_DART_BASE + DART_PARAMS1);
  params2 = MmioRead32 (WINM_DART_BASE + DART_PARAMS2);
  tcr = MmioRead32 (WINM_DART_BASE + DART_T8020_TCR);
  page_shift = (params1 >> DART_PARAMS1_PAGE_SHIFT) & 0xFU;

  Print (L"WinM: DART base=0x%lx params1=0x%x params2=0x%x tcr=0x%x page_shift=%u\n",
         WINM_DART_BASE, params1, params2, tcr, page_shift);
  return EFI_SUCCESS;
}
