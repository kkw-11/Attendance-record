# Attendance-record

## Description
- 출근 기록 관리 프로그램 개발
- Arduino Client 카드리더기에 카드 인식을 하면 등록된 카드라면 Raspberry Pi Server로 카드 정보 전송, 출근 시간 DB에 저장, 등록되지 않은 카드라면 Buzzer를 울림

## Tech Stack
 ### Client(Arduino)
  - Arduino, RFID(Radio-Frequency Identification), LED, Buzzer, Resitance
 ### Server(Raspberry Pi)
  - C, Mysql, Raspberry Pi

![image](https://user-images.githubusercontent.com/76929823/113664832-6c172500-96e7-11eb-847a-8048d257b5f3.png)

### Client
![image](https://user-images.githubusercontent.com/76929823/113664683-278b8980-96e7-11eb-8de1-f6b9487a46fd.png)

### Server
![image](https://user-images.githubusercontent.com/76929823/113665039-c4e6bd80-96e7-11eb-8940-59a4ff9cc073.png)


## 아쉬운 점(개선 사항)
- 기존 등록된 카드를 클라이언트에서 처리하는 것을 개선하여 새로운 카드 정보를 DB에 저장하는 과정 추가하고 등록된 카드인지 여부를 서버에서 처리하도록 개선하는 과정 필요



