see also: [Virtual Memory Map](MemMapVirtual.md)


| `00000000`<br>8MB<br><code>007fffff</code> <table><thead><th> <a href='MemMapROM.md'>OS ROM</a> </th></thead><tbody>
<tr><td> <code>00800000</code><br>8MB<br><code>00ffffff</code> </td><td>  (Einstein ROM Extension) </td></tr>
<tr><td>...</td></tr>
<tr><td> <code>02000000</code><br>4MB<br><code>023fffff</code> </td><td> <a href='MemMapFlash.md'>1st Flash Memory Bank</a> </td></tr>
<tr><td>...</td></tr>
<tr><td> <code>04000000</code><br>4MB<br><code>043fffff</code> </td><td> <a href='MemMapRAM.md'>RAM (physical)</a> </td></tr>
<tr><td>...</td></tr>
<tr><td> <code>0f000000</code><br>?MB<br><code>0fffffff</code> </td><td> <a href='MemMapIO.md'>Hardware I/O Registers</a> </td></tr>
<tr><td>...</td></tr>
<tr><td> <code>10000000</code><br>4MB<br><code>103fffff</code> </td><td> <a href='MemMapFlash.md'>2nd Flash Memory Bank</a> </td></tr>
<tr><td>...</td></tr>
<tr><td> <code>30000000</code> </td><td> <a href='MemPCMCIA.md'>PCMCIA Card 0 Base</a> </td></tr>
<tr><td> <code>40000000</code> </td><td> <a href='MemPCMCIA.md'>PCMCIA Card 1 Base</a> </td></tr>