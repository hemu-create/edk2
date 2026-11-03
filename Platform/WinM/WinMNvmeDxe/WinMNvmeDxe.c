#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/IoLib.h>
#include "WinMRegisters.h"

EFI_STATUS
EFIAPI
WinMNvmeDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  UINT32 cap_lo;
  UINT32 cap_hi;
  UINT32 version;
  UINT32 cc;
  UINT32 csts;

  if (WINM_NVME_BASE == 0) {
    Print (L"WinM: NVMe base is not documented for M3; skipping probe\n");
    return EFI_SUCCESS;
  }

  cap_lo = MmioRead32 (WINM_NVME_BASE + NVME_REG_CAP);
  cap_hi = MmioRead32 (WINM_NVME_BASE + NVME_REG_CAP + 4);
  version = MmioRead32 (WINM_NVME_BASE + NVME_REG_VS);
  cc = MmioRead32 (WINM_NVME_BASE + NVME_REG_CC);
  csts = MmioRead32 (WINM_NVME_BASE + NVME_REG_CSTS);

  Print (L"WinM: NVMe base=0x%lx CAP=0x%08x%08x VS=0x%x CC=0x%x CSTS=0x%x\n",
         WINM_NVME_BASE, cap_hi, cap_lo, version, cc, csts);
  return EFI_SUCCESS;
}
