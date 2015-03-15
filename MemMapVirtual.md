see also: [Newton OS 2.1 Physical Memory Map](MemoryMap.md)

| `00000000` | ROM at `00000000`, Domain 0 (unless patched!) |
|:-----------|:----------------------------------------------|
| `00800000` <br> <code>00f00000</code> <table><thead><th> ROM Extension at <code>00800000</code>, Domain 0 </th></thead><tbody>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>01800000</code> <br>  <code>0180ffff</code></td><td> at <code>00013000</code>, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>01a00000</code> <br>  <code>01c1ffff</code></td><td> ROM Jump Tables at <code>00002000</code>, Domain 0, may get patched, sparse use </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>01d80000</code> <br>  <code>01d9ffff</code></td><td> Magic Pointer Table at <code>003af000</code>, Domain 0, may get patched, sparse use </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>01e00000</code> <br>  <code>01efffff</code></td><td> REx Jump Table at <code>007ee000</code>, Domain 0, may get patched, sparse use </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>03500000</code> <br> <code>03cfffff</code> </td><td> Mirror of ROM at <code>00000000</code>, rw/ro, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>04000000</code> <br> <code>040fffff</code> </td><td> Mirror of ROM start at <code>00000000</code>, rw/ro, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>05000000</code> <br> <code>051fffff</code> </td><td> Mirror of first half of Flash Bank 1 at <code>02000000</code>, rw/rw, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0c000000</code> <br> <code>0c000fff</code> </td><td> RAM, 1k rw/na blocks, Domain 0 </td></tr>
<tr><td>  </td><td> <code>0c000400</code>: Kernel Stack, maps to <code>04004000</code> </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0c002000</code> <br> <code>0c008fff</code> </td><td> RAM, 1k rw/na blocks, Domain 0 </td></tr>
<tr><td>  </td><td> <code>0c002c00</code>: IRQ Stack </td></tr>
<tr><td>  </td><td> <code>0c003400</code>: FIQ Stack </td></tr>
<tr><td>  </td><td> <code>0c004000</code>: svc Stack </td></tr>
<tr><td>  </td><td> <code>0c004c00</code>: Abort Stack </td></tr>
<tr><td>  </td><td> <code>0c006000</code>: Undef Stack </td></tr>
<tr><td>  </td><td> <code>0c007400</code>: User Stack </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0c100000</code> <br> <code>0c125fff</code> </td><td> RAM, rw/rw, Domain 2 </td></tr>
<tr><td>  </td><td> <code>0c100000</code>: Kernel Domain Heap Base </td></tr>
<tr><td>  </td><td> <code>0c100800</code>: gKernelArea, Kernel Globals Base (end = 0c107e14), many symbols available here! </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0c200000</code> <br> <code>0c205fff</code> </td><td> RAM, rw/rw, Domain 3 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0c310000</code> <br> <code>0c328fff</code> </td><td> RAM, rw/rw, Domain 3, only 1k or 2k blocks </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0c600000</code> <br> <code>0c675fff</code> </td><td> RAM, rw/rw, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0c984000</code> <br> <code>0c984fff</code> </td><td> RAM, rw/rw, Domain 0, 2k block </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0ca6b000</code> <br> <code>0ca8ffff</code> </td><td> RAM, rw/rw, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0cc79000</code> <br> <code>0ccedfff</code> </td><td> RAM, rw/rw, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0cd58000</code> <br> <code>0cdfefff</code> </td><td> RAM, rw/rw, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0ce17000</code> <br> <code>0ce17fff</code> </td><td> RAM, rw/rw, Domain 0, 1k </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0ce30000</code> <br> <code>0ce30fff</code> </td><td> RAM, rw/rw, Domain 0, 1k </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>0f000000</code> <br> <code>2fffffff</code> </td><td> hardware registers, maps to self, rw/rw, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>30000000</code> </td><td> Flash Memory Bank 1 at <code>02000000</code>, rw/ro, Domain 0 </td></tr>
<tr><td> <code>30400000</code> <br> <code>30700000</code> </td><td> Flash Memory Bank 2 at <code>10000000</code>, rw/ro, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>34000000</code> </td><td> Flash Memory Bank 1 at <code>02000000</code>, rw/rw, Domain 0 </td></tr>
<tr><td> <code>34400000</code> <br> <code>34700000</code> </td><td> Flash Memory Bank 2 at <code>10000000</code>, rw/rw, Domain 0 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>60000000</code> </td><td> This area seems to be mapping Flash content into RAM (packages, large binaries, etc.) </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>9c000000</code> <br> <code>9fffffff</code> </td><td> maps to PCMCIA Control 0 at <code>3c000000</code>, rw/rw, Domain 1 </td></tr>
<tr><td> ... </td><td>  </td></tr>
<tr><td> <code>ac000000</code> <br> <code>afffffff</code> </td><td> maps to PCMCIA Control 1 at <code>4c000000</code>, rw/rw, Domain 1 </td></tr></tbody></table>

End of MMU table. A physical device would have additional mappings for the virtual Screen Memory at <code>e0000000</code> and maybe others. If a ROM patch was applied, many entries in this table would be quite different.