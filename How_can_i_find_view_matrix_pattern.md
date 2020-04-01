# How Can I Find Pubg Mobile View Matrix Pattern



**[Youtube Video](https://www.youtube.com/watch?v=ya0rbAwFKdY)**
[![PUBG ESP EXAMPLE SCREENSHOT](https://raw.githubusercontent.com/atiksoftware/pubg_mobile_memory_hacking_examples/master/screens/How%20Can%20I%20Find%20Pubg%20Mobile%20Gameloop%20ViewMatrix%20Pattern.png)](https://www.youtube.com/watch?v=ya0rbAwFKdY)

- Join to Training.  
- Take a sniper, and get 8x scoop.  
- Go to there as in video  
- Zoom to tareget center (150m) 

viewmatrix 4x4 16 float. its 16*4 64Byte
if you zoom to this target with 8x scoop.  
your view matrix some like this.
```
-12.0 <-> -12.0
-0.012 <-> 0.012
0.0
0.092 <-> 0.102
0.900 <-> 1.100
-0.100 <-> 0.100
0
0.990 <-> 0.999
0
18.0 <-> 19.0
0
-0.007 <-> 0.007
1000000.0 <-> 8000000.0 || 1 == 1
-30000.0 <-> -10000.0
3
-80000.0 <-> -10000.0 || 1 == 1
```
--- 

## Find viewmatrix base
```C++
	loadRegions(0x340F4E00, 0x5F9CFEB0);
 
	float _f;

	DWORD foundedVMPath = 0; 
	//for(int r = 0; r < memSectorIndex; r++){
	for(int r = 0; r < memSectorIndex; r++){
		std::cout << termcolor::blue << " region: " << (r + 1) << "/" << memSectorIndex << "  base: " << termcolor::cyan << "0x" << std::hex << memSectorList[r].dwBaseAddr << termcolor::reset << " size: " << std::dec << memSectorList[r].dwMemorySize << "\n";

		MEMORY_REGION region = memSectorList[r];
		DWORD base = region.dwBaseAddr;
		int size = region.dwMemorySize; 
		loadBuffer(base, size); 
		 
		for(int i = 0; i < size - 4; i+=4){ 
			_f = flook( i);
			if( _f > -11.0f && _f < -10.0f){ // 10
				_f = flook( i + 4);
				if( _f > -0.012 && _f < 0.012){ // 11
					_f = flook( i + 8);
					if(flook( i + 8) == 0.0f){ // 12
						_f = flook( i + 12);
						if(_f > 0.092f && _f < 0.102f){ // 13
							_f = flook( i + 16);
							if(_f > 0.900f && _f < 1.100f){ // 14
								_f = flook( i + 20);
								if(_f > -0.100f && _f < 0.100f){ // 15
									_f = flook( i + 24);
									if(_f == 0.0f){ // 16
										_f = flook( i + 28);
										if(_f > 0.990f && _f < 0.999f){ // 17
											_f = flook( i + 32);
											if(_f != 0.0f || 1 == 1){ // 18 - unknown
												_f = flook( i + 36);
												if(_f > 18.0f && _f < 19.0f){ // 19
													_f = flook( i + 40);
													if(_f == 0.0f){ // 20
														_f = flook( i + 44);
														if(_f > -0.007f && _f < 0.007f){ // 21
															_f = flook( i + 48);
															if(_f > 10000.0f && _f < 8000000.0f || 1 == 1){ // 22 - unknown
																_f = flook( i + 52);
																if(_f > -30000.0f && _f < -10000.0f){ // 23
																	_f = flook( i + 56);
																	if(_f == 3.0f){ // 24
																		_f = flook( i + 60);
																		if(_f > -800000.0f && _f < -100000.0f || 1 == 1){ // 25 - unknown
																			if(flook(i + 64) == 0.0f && flook(i + 68) == 0.0f && flook(i + 72) == 0.0f){ // END + 12byte 
																				std::cout << "Found : " << std::hex << base + i << std::dec << "\n";
																				foundedVMPath = base + i;
																				r = memSectorIndex;
																				int ax = 22;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			} 
		} 
	}
```



## Find Which Pointers Goint To ViewMatrix

```C++
	loadRegions(0x26000000, 0x30000000);
	DWORD _1, _2, _3;
	for(int r = 0; r < memSectorIndex; r++){
		std::cout << termcolor::blue << " region: " << (r+1) << "/" << memSectorIndex << "  base: " << termcolor::cyan << "0x" << std::hex << memSectorList[r].dwBaseAddr << termcolor::reset << " size: " << std::dec << memSectorList[r].dwMemorySize << "\n";
		MEMORY_REGION region = memSectorList[r];
		DWORD base = region.dwBaseAddr;
		int size = region.dwMemorySize;
		loadBuffer(base, size);
		for(int i = 0; i < size - 4; i += 4){
			_1 = dlook(i);
			if(_1 > 0x2C8475E0 && _1 < 0x5C8475E0){
				for(int g = 0; g < 200; g += 4){
					_2 = dread(_1 + g);
					if(_2 > 0x2C8475E0){
						for(int h = 0; h < 1024; h += 4){
							if(_2 + h == foundedVMPath){
								std::cout << termcolor::green;
								std::cout << "Found Base: "; 
								std::cout << termcolor::red;
								logHex((base + i));
								std::cout << termcolor::reset;
								std::cout << " >"; 
								std::cout << termcolor::red;
								std::cout << " +0x";
								logHex(g);
								std::cout << termcolor::reset;
								std::cout << " >";
								std::cout << termcolor::red;
								std::cout << " +0x"; 
								logHex(h);
								std::cout << termcolor::reset;
								logStr("\n");
								std::cout << termcolor::reset;
								std::string xxx;
								std::cin >> xxx;
							}
						}
					}
				}
			} 
		} 
	}
```