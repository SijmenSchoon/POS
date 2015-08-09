#include <gdt.h>
#include <stdint.h>
#include <assert.h>

#define GDT_PACK_ENTRY(base, limit, access, flags) ( \
    (((limit      ) & 0x0000ffff) << 0 ) | \
    (((base       ) & 0x00ffffff) << 16) | \
    (((access     ) & 0x000000ff) << 40) | \
    (((limit >> 16) & 0x0000000f) << 48) | \
    (((flags      ) & 0x0000000f) << 52) | \
    (((base  >> 24) & 0x000000ff) << 56)   \
)

typedef volatile struct
{
    uint16_t size;
    uint32_t offset;
} __attribute__((__packed__)) gdt_desc_t;

typedef volatile struct
{
    uint16_t link;
    uint16_t reserved_0;

    uint32_t esp0;
    uint16_t ss0;
    uint16_t reserved_1;

    uint32_t esp1;
    uint16_t ss1;
    uint16_t reserved_2;

    uint32_t esp2;
    uint16_t ss2;
    uint16_t reserved_3;

    uint32_t cr3;
    uint32_t eip;
    uint32_t eflags;

    uint32_t eax;
    uint32_t ecx;
    uint32_t edx;
    uint32_t ebx;

    uint32_t esp;
    uint32_t ebp;

    uint32_t esi;
    uint32_t edi;

    uint16_t es;
    uint16_t reserved_4;

    uint16_t cs;
    uint16_t reserved_5;

    uint16_t ss;
    uint16_t reserved_6;

    uint16_t ds;
    uint16_t reserved_7;

    uint16_t fs;
    uint16_t reserved_8;

    uint16_t gs;
    uint16_t reserved_9;

    uint16_t ldtr;
    uint16_t reserved_a;

    uint16_t reserved_b;
    uint16_t iopb_offset;
} tss_t;

static uint64_t gdt[4] = {
    GDT_PACK_ENTRY(0, 0, 0, 0x4),
    GDT_PACK_ENTRY(0, 0xfffff, 0x9a, 0xc),
    GDT_PACK_ENTRY(0, 0xfffff, 0x92, 0xc),
    GDT_PACK_ENTRY(&tss, sizeof(tss), 0x89, 0x4)
};

void gdt_setup(struct tss_t **tss)
{
    struct gdt_desc gdtd = { .size = sizeof(gdt), \
        .offset = (uint32_t)gdt - 0xc0000000 };
    asm volatile("lgdt %0" :: "m"(&gdtd));
}
