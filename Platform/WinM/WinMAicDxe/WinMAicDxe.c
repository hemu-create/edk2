#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/IoLib.h>
#include "WinMRegisters.h"

EFI_STATUS
EFIAPI
WinMAicDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  UINT32 info;
  UINT32 config;
  UINT32 whoami;
  UINT32 event;
  UINT32 nr_irq;
  UINTN index;

  info = MmioRead32 (WINM_AIC_BASE + AIC_INFO);
  config = MmioRead32 (WINM_AIC_BASE + AIC_CONFIG);
  whoami = MmioRead32 (WINM_AIC_BASE + AIC_WHOAMI);
  event = MmioRead32 (WINM_AIC_BASE + AIC_EVENT);
  nr_irq = info & AIC_INFO_NR_IRQ;

  for (index = 0; index < (AIC_MAX_IRQ / 32U); index++) {
    MmioWrite32 (WINM_AIC_BASE + AIC_MASK_SET + index * 4, 0xFFFFFFFFU);
  }

  Print (L"WinM: AIC base=0x%lx info=0x%x config=0x%x whoami=0x%x event=0x%x irqs=%u\n",
         WINM_AIC_BASE, info, config, whoami, event, nr_irq);
  return EFI_SUCCESS;
}
