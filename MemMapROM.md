see also: [Memory Map](MemoryMap.md)

The Newton ROM is devided into two major parts. The first part is the code that is executed at startup and during run time. The second part is a "ROM Extension". NewtonOS supports multiple ROM Extensions that contain all kinds of data.

An optional ROM extension can be placed at 8MB. Einstein uses this REx to replace the original NewtonOS drives with Einstein specific drivers that call native code to do their business.

`00000000` to `007fffff`
| `00000000`<br>8MB<br><code>0071FC48</code> <table><thead><th> <a href='MemMapROMOS.md'>NewtonOS</a> </th></thead><tbody>
<tr><td> <code>0071FC4C</code><br>900kB<br><code>0x7FB810</code> </td><td> <a href='MemMapROMRex.md'>ROM Extension</a> (REx) </td></tr>
<tr><td> <code>7FB814</code><br>4MB<br><code>007fffff</code> </td><td> (empty) </td></tr>