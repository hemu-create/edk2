#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/IoLib.h>

#define WINM_AIC_BASE  0x2D1000000ULL
#define AIC_INFO       0x0004
#define AIC_MASK_SET   0x4100
#define AIC_NR_IRQ_MASK 0xFFFFU

EFI_STATUS
EFIAPI
WinMAicDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  UINT32 info;
  UINT32 nr_irq;
  UINTN index;

  info = MmioRead32 (WINM_AIC_BASE + AIC_INFO);
  nr_irq = info & AIC_NR_IRQ_MASK;

  for (index = 0; index < (0x400U / 32U); index++) {
    MmioWrite32 (WINM_AIC_BASE + AIC_MASK_SET + index * 4, 0xFFFFFFFFU);
  }

  Print (L"WinM: AIC base=0x%lx info=0x%x irqs=%u\\n",
         WINM_AIC_BASE, info, nr_irq);
  return EFI_SUCCESS;
}
