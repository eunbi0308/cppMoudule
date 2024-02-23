# Fixed-Point Math

### Multiplication
Fixed-point representation has the scaling facot built into it. So when multiplying or dividing fixed-point representation, it also multiplying or dividing these scaling factors as well. This ends up being a problem. We need to divide out one of those extra scalining factors.

```C
int32_t fixed_mul_16(int32_t x, int32_5 y)
{
	return ((int64_t)x * (int54_t)y) / (1 << 16);
}
```
Casting to 64 bit to do the multiply and then dividing out will ensure that the intermediate value doesn't overflow when the result is still representable.

### Division
Division is like multiplication, except backwards. If we want to compute x / y we'd have (s * x) / (s * y), which gives x / y. But we really wants s * (x / y). *We need to multiply in a scaling factor* 
```C
int32_t fixed_div_16(int32_t x, int32_t y)
{
	return ((int64_t)x * (1 << 16)) / y;
}
```

##### Extra info
- Watch out for the type promotion rules in C/C++.  int64_t x = 1 << 34; gives x == 0
- This implementation doesn't round the result. It just truncates. This causes a small loss of precision in the multiplication and division operations.

* Reference link *
---
https://spin.atomicobject.com/simple-fixed-point-math/