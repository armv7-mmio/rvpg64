CC = x86_64-w64-mingw32-clang
AS = nasm

BUILD_DIR = ../build/bootloader
TARGET_EFI = $(BUILD_DIR)/BOOTX64.EFI

CFLAGS = -fno-stack-protector -ffreestanding -target x86_64-w64-mingw32 \
	-nostdlib -fshort-wchar -mno-red-zone \
	-I /usr/include/efi -I /usr/include/efi/x86_64
LDFLAGS = -Wl,-e,efi_main -Wl,--subsystem,efi_application -fuse-ld=lld \
	  -l:libefi.a -L /usr/lib

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))

all: $(TARGET_EFI)

$(TARGET_EFI): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@ 

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@
$(BUILD_DIR): 
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
