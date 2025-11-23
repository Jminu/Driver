# Raspberry Pi sensor, lcd driver for Monitoring System

## Overview
리눅스 커널 레벨의 디바이스 드라이버를 직접 구현. SHT20과 HD44780(I2C LCD)를 제어하고, 멀티 프로세세스 및 공유 메모리 기법을 활용하여 실시간 데이터 모니터링하는 간단한 시스템

---
## Teck Stack
+ Hardware: Raspberry Pi 4B, SHT20, HD44780, Tactile Button
+ Kernel Space: 문자 디바이스 드라이버, i2c, 인터럽트 핸들링, wait queue
+ User Space: Multi-process, IPC(shared memory), read/write
+ Tools: GCC, Makefile, Datasheet

---
## Feature
### SHT20 (i2c) 온/습도 센서


### HD44780+i2c확장 모듈


### 버튼 IRQ
버튼 디바이스를 상대로 read를 했을 때 해당 유저 프로세스를 wait queue에서 대기시키고, 버튼 인터럽트가 발생했을 때 run queue로 옮기며 프로세스를 깨운다.

-> CPU활용 높아짐

인터럽트 발생하면 시스템 모드 플래그를 토글하여 유저 프로세스로 전달.

