#include <efi.h>
#include <efilib.h>

// Точка входа, которую мы указали в LDFLAGS (-Wl,-entry:efi_main)
EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    // 1. Инициализируем библиотеку gnu-efi
    // Она настраивает глобальные указатели, такие как ST (SystemTable)
    InitializeLib(ImageHandle, SystemTable);

    // 2. Очищаем экран (необязательно, но полезно)
    SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

    // 3. Выводим строку. 
    // ВАЖНО: строки в UEFI должны быть 16-битными (UTF-16), 
    // поэтому используем префикс L
    Print(L"Hello, World from UEFI!\n");
    Print(L"Press any key to continue...\n");

    // 4. Ожидаем нажатия клавиши, чтобы успеть прочитать текст
    UINTN index;
    EFI_EVENT event = SystemTable->ConIn->WaitForKey;
    SystemTable->BootServices->WaitForEvent(1, &event, &index);

    return EFI_SUCCESS;
}
