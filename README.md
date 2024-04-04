## 프로젝트 소개

- Unreal Engine으로 온라인 RPG 기능을 구현
- 캐릭터 조작 및 몬스터 패턴 구현
- Unreal Network를 이용하여 서버와 클라이언트를 동기화

## 시연 영상

https://youtu.be/E_dTuCVt-Ik

## 목차

1. 로그인 기능 구현
2. 캐릭터 기능 구현
3. 몬스터 패턴 구현
4. Unreal Network를 이용한 서버, 클라이언트 동기화
5. NPC 기능 구현


### 1. 로그인 기능 구현

- 회원가입 시 Firebase에 데이터 저장
- 중복 아이디 가입 방지
  
    ![회원가입장면](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/dd135b7b-ef3b-4212-8fe5-e0ba93d5c6ce)


    
- Firebase에 저장된 데이터 비교 후 로그인
  
    ![로그인장면](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/78f3a902-0bb4-4d9f-bc5c-a7a0b7c3af7f)


  

### 2. 캐릭터 기능 구현

- 캐릭터 애니메이션 스테이트 머신으로 구현
  
![image](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/9dcefce6-fead-41ba-b158-e17538bdb749)



- 캐릭터 이동, 공격, 스킬 등 기능 구현
- 땅, 풀숲, 물가에서 서로 다른 걷기 사운드 출력
  
![캐릭터기본조작](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/4d2b2a6c-5db3-4e97-81ed-e665dbeeaddf)



- 인벤토리 기능 구현
- 언리얼 데이터 테이블로 아이템 정보 관리

  ![image](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/1b168b3d-b5ab-4dc6-8867-53234e2cea16)



- Firebasefh 플레이어의 인벤토리 정보 관리
  
![image](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/4fe29c7f-3a34-455f-9326-4afdbebf6948) ![언리얼온라인3](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/d39a21e7-2fc2-4237-adbe-56b9c4a46067)  ![언리얼온라인4](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/257e845d-2690-4b80-99e7-4c99e43302ee)




### 3. 몬스터 패턴 구현

- Behavior Tree를 이용한 몬스터 패턴 구현
- 피격 시 해당 플레이어를 타겟으로 추적
- 타겟 근접 시 공격
  
![Greek_Island3](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/ba8d3ad5-a62a-424f-a167-17fbfaa58891)




### 4. Unreal Network를 이용한 서버, 클라이언트 동기화

- 캐릭터, 몬스터, 아이템 등 오브젝트 동기화
- 프로퍼티 리플리케이션과 RPC를 사용하여 애니메이션, 이펙트 등 동기화
  
![언리얼온라인1](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/47f2d59a-91a4-4687-a9d2-4f874ddc0b07) ![언리얼온라인2](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/58e653fc-f036-4807-acac-d794197e9ca9) ![언리얼온라인5](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/aa0dfd07-b8fe-419a-ab7f-9353ecb105a4)




### 5. NPC 기능 구현

- NPC 및 퀘스트 구현
- 퀘스트 조건 달성 시 보상 획득
  
![NPC퀘스트](https://github.com/kdm6859/UNREAL_Online_RPG/assets/64892955/805ff674-8a18-47ab-a3be-662df5f9fba2)

