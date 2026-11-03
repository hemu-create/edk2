# WinM EDK2 Apple Silicon Platform

This fork is the WinM firmware tree. It is not a generic `ArmVirtQemu` build and
is not bootable on Apple Silicon yet. The purpose of this tree is to hold the
platform-specific EDK2 changes needed by WinM.

## Boot chain

```text
iBoot -> m1n1 stage 1 -> m1n1 stage 2 -> b00t (EL2) -> EDK2 (EL1) -> Windows
```

b00t owns EL2, stage-2 translation, PSCI over HVC, and the virtual interrupt
controller. EDK2 runs at EL1 and provides UEFI boot services, runtime services,
ACPI tables, GOP, block I/O, and the Windows boot path.

## Required platform work

- AIC/AICv3 physical interrupt driver and b00t virtual-GIC handoff.
- DART IOMMU driver with 16 KiB granule support and 4 KiB Windows bounce buffers.
- Apple NVMe controller and namespace driver.
- USB xHCI/DWC3, Type-C, and keyboard/trackpad input.
- Simple framebuffer or DCP display driver for GOP.
- RTC, PMU/SMC, watchdog, and reset services.
- UEFI variable store on the EFI System Partition during bring-up.
- ACPI DSDT/SSDT generation and handoff from b00t.
- SMBIOS and device-path descriptions for Windows.
- Secure Boot policy and signed driver strategy.

## Build

This tree is intended to build with the standard EDK2 build system once the
platform DSC/FDF and silicon drivers exist. Current status is design-only.

```sh
git clone --recursive https://github.com/hemu-create/edk2.git
cd edk2
. edksetup.sh
build -a AARCH64 -t GCC5 -p Platform/WinM/AppleSilicon/WinMAppleSilicon.dsc
```

The DSC/FDF are not present yet. Do not treat this tree as a working firmware.
