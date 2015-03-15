see also: see also: [Memory Map](MemoryMap.md)

The RAM will be mapped to various places in virtual memory using the MMU lookup table.

Physical Map:
| `04000000` | 1st level MMU table (16kB) |
|:-----------|:---------------------------|
| `04004000` | Start of Super Stack in Physical Memory, Virtual Address: `0c000000` |
| `043c0000`<br><code>043fffff</code> <table><thead><th> Physical Video RAM: 320x480/2=76800 bytes </th></thead><tbody>