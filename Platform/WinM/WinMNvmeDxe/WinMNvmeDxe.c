#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/IoLib.h>
#include "WinMRegisters.h"

/*
 * Documented ANS2 NVMe MMIO base from the Apple Silicon device tree binding.
 * M3 uses the same ANS2 NVMe family; the M3-specific base is not present in
 * the minimal M3 device tree, so this uses the documented M1 ANS2 base until
 * an M3 device tree provides the exact value.
 */
#define WINM_NVME_BASE 0x27BCC0000ULL

#define NVME_REG_CAP 0x00
#define NVME_REG_VS 0x08

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

  cap_lo = MmioRead32 (WINM_NVME_BASE + NVME_REG_CAP);
  cap_hi = MmioRead32 (WINM_NVME_BASE + NVME_REG_CAP + 4);
  version = MmioRead32 (WINM_NVME_BASE + NVME_REG_VS);

  Print (L"WinM: NVMe base=0x%lx CAP=0x%08x%08x VS=0x%x\\n",
         WINM_NVME_BASE, cap_hi, cap_lo, version);
  return EFI_SUCCESS;
}
