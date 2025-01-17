# DA1469x Adesto AT25SL321 Flash driver

______________________________________________________________________

## Example description

This example downloads and runs FreeRTOS Retarget project with the Adesto AT25SL321 QSPI Flash attached to the DA1469x device.

## HW and SW configuration

- **Hardware configuration**

  - This example runs on The DA1469X Bluetooth Smart SoC devices.
  - The Pro Development kit or USB is needed for this example.
  - Connect the Development kit to the host computer.
  - The development kit needs to have the flash replaced with Adesto AT25SL321.

- **Software configuration**

  - This example requires:

  * SmartSnippetsStudio 2.0.12 or newer
  * SDK10.0.8.105 or newer

  - **SEGGER J-Link** tools should be downloaded and installed.

## How to run the example

### Initial Setup

- Compile the QSPI target version of the project.

- Move the file qspi_at25sl321.h found under {project_root}/config, to {SDK_root}/sdk/bsp/memory/include folder

- In sdk/bsp/memory/src folder, automode.c file find the following snippet

  `#if (FLASH_AUTODETECT == 1)`

  where the drivers are included and include driver qspi_at25sl321.h.
  Additionally right after that, where static const qspi_flash_config_t\* flash_config_table\[\] is defined, add the configuration object to the array by adding ...
  `&flash_at25sl321_config,`

- Recompile the uartboot, libprogrammer and cli_programmer projects with the added flash driver files.

- Program the device and reboot

- Use your preferred terminal to the serial port (FTDI lower index port) with the following parameters

  - baudrate: 115200
  - data: 8 bits
  - stop: 1 bit
  - parity: None
  - flow  control: none

- The terminal displays the "#" characters every second.

### Flash Configuration Setup

Under {SDK_root}/utilities/python_scripts/qspi folder, edit file flash_configurations.xml and add the following configuration.

```
  <configuration name="Adesto AT25SL321">
    <flash_size>0x400000</flash_size>
    <flash_burstcmda_reg_value>0xa8a000eb</flash_burstcmda_reg_value>
    <flash_burstcmdb_reg_value>0x00000066</flash_burstcmdb_reg_value>
    <flash_write_config_command>0x31 0x02 0x07</flash_write_config_command>
  </configuration>
```

Pick the 'program_qspi_config' option before burning any firmware to the new device. In the subsequent windows make the following choices.

- Product ID: 					      DA1469x-00
- Flash:           					      Adesto AT25SL321
- active_image_address:       0x2000
- update_image_address:     0x2000

## Known Limitations

- There are no known limitations for this example.
