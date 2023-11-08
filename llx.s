0000000000001346 <func4>:
    1346: 53                    push   %rbx
    1347: 89 d0                 mov    %edx,%eax # eax = z
    1349: 29 f0                 sub    %esi,%eax # eax = z - y
    134b: 89 c3                 mov    %eax,%ebx # ebx = z - y
    134d: c1 eb 1f              shr    $0x1f,%ebx # ebx = (z - y) >> 31
    1350: 01 c3                 add    %eax,%ebx # ebx = z - y + (z - y >> 31)
    1352: d1 fb                 sar    %ebx # ebx = ebx / 2 = (z - y + (z - y >> 31)) / 2 实现向0取整
    1354: 01 f3                 add    %esi,%ebx # ebx = y + ebx = y + (z - y + (z - y >> 31)) / 2
    1356: 39 fb                 cmp    %edi,%ebx
    1358: 7f 08                 jg     1362 <func4+0x1c> # if ebx > x
    135a: 39 fb                 cmp    %edi,%ebx
    135c: 7c 10                 jl     136e <func4+0x28> # if ebx < x
    135e: 89 d8                 mov    %ebx,%eax # return ebx
    1360: 5b                    pop    %rbx
    1361: c3                    retq   
    1362: 8d 53 ff              lea    -0x1(%rbx),%edx # if ebx > x edx = ebx - 1
    1365: e8 dc ff ff ff        callq  1346 <func4> # 递归调用
    136a: 01 c3                 add    %eax,%ebx # ebx = ebx + eax
    136c: eb f0                 jmp    135e <func4+0x18>  # return ebx
    136e: 8d 73 01              lea    0x1(%rbx),%esi # if ebx < x esi = ebx + 1
    1371: e8 d0 ff ff ff        callq  1346 <func4> # 递归调用
    1376: 01 c3                 add    %eax,%ebx # ebx = ebx + eax
    1378: eb e4                 jmp    135e <func4+0x18> # return ebx

000000000000137a <phase_4>:
    137a: 48 83 ec 18           sub    $0x18,%rsp
    137e: 64 48 8b 04 25 28 00  mov    %fs:0x28,%rax
    1385: 00 00 
    1387: 48 89 44 24 08        mov    %rax,0x8(%rsp) # 防止栈越界
    138c: 31 c0                 xor    %eax,%eax # 置0
    138e: 48 8d 4c 24 04        lea    0x4(%rsp),%rcx # 第二个数 y
    1393: 48 89 e2              mov    %rsp,%rdx # 第一个数 x
    1396: 48 8d 35 f8 18 00 00  lea    0x18f8(%rip),%rsi        # 2c95 <array.3417+0x255>
    139d: e8 3e fb ff ff        callq  ee0 <__isoc99_sscanf@plt>
    13a2: 83 f8 02              cmp    $0x2,%eax
    13a5: 75 06                 jne    13ad <phase_4+0x33>
    13a7: 83 3c 24 0e           cmpl   $0xe,(%rsp)
    13ab: 76 05                 jbe    13b2 <phase_4+0x38> # should have x <= 14
    13ad: e8 e3 05 00 00        callq  1995 <explode_bomb>
    13b2: ba 0e 00 00 00        mov    $0xe,%edx # edx = 14
    13b7: be 00 00 00 00        mov    $0x0,%esi # esi = 0
    13bc: 8b 3c 24              mov    (%rsp),%edi # edi = x
    13bf: e8 82 ff ff ff        callq  1346 <func4>
    13c4: 83 f8 15              cmp    $0x15,%eax
    13c7: 75 07                 jne    13d0 <phase_4+0x56> # should have eax = 21
    13c9: 83 7c 24 04 15        cmpl   $0x15,0x4(%rsp)
    13ce: 74 05                 je     13d5 <phase_4+0x5b> # should have 2nd number = 21
    13d0: e8 c0 05 00 00        callq  1995 <explode_bomb>
    13d5: 48 8b 44 24 08        mov    0x8(%rsp),%rax # 防止栈越界
    13da: 64 48 33 04 25 28 00  xor    %fs:0x28,%rax
    13e1: 00 00 
    13e3: 75 05                 jne    13ea <phase_4+0x70>
    13e5: 48 83 c4 18           add    $0x18,%rsp
    13e9: c3                    retq   
    13ea: e8 51 fa ff ff        callq  e40 <__stack_chk_fail@plt>