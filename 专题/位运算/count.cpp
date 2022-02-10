/*
* @Author: wilson_t
* @Date:   2021-06-21 10:07:42
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-21 10:08:56
*/

//__builtin_popcount
unsigned popcount (unsigned u) {
    u = (u & 0x55555555) + ((u >> 1) & 0x55555555);
    u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
    u = (u & 0x0F0F0F0F) + ((u >> 4) & 0x0F0F0F0F);
    u = (u & 0x00FF00FF) + ((u >> 8) & 0x00FF00FF);
    u = (u & 0x0000FFFF) + ((u >> 16) & 0x0000FFFF);
    return u;
}