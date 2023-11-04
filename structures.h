struct Vector3 
{
	int x, y, z;
};


class playerObj
{
public:
	Vector3 CameraPos; //0x0004
	Vector3 xyzVelocity; //0x0010
	char pad_001C[36]; //0x001C
	Vector3 ViewPos; //0x0040
	char pad_004C[172]; //0x004C
	int32_t Health; //0x00F8
	int32_t Shield; //0x00FC
	char pad_0100[20]; //0x0100
	int32_t SecondaryReserveAmmo; //0x0114
	char pad_0118[16]; //0x0118
	int32_t PrimaryReserveAmmo; //0x0128
	char pad_012C[16]; //0x012C
	int32_t SecondaryInClip; //0x013C
	char pad_0140[16]; //0x0140
	int32_t PrimaryInClip; //0x0150
	char pad_0154[16]; //0x0154
	int32_t SecondaryWaitTime; //0x0164
	char pad_0168[16]; //0x0168
	int32_t PrimaryWaitTime; //0x0178
	char pad_017C[12]; //0x017C
	int32_t TotalKnifeShots; //0x0188
	char pad_018C[20]; //0x018C
	int32_t TotalPrimaryShots; //0x01A0
	char pad_01A4[128]; //0x01A4
	bool bShooting; //0x0224
	char Username[16]; //0x0225
	char pad_0235[247]; //0x0235
	int32_t teamNum; //0x032C
	char pad_0330[64]; //0x0330
	char MyPad[4];
	class WeaponObj* CurrentWeaponPtr; //0x0374
	char MyPad1[4];
	char pad_037C[324]; //0x037C

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x04C0

class WeaponObj
{
public:
	char pad_0004[4]; //0x0004
	class playerObj* ownerObjPtr; //0x0008
	class weaponInfo* weaponInfoPtr; //0x000C
	char pad_0010[4]; //0x0010
	class N000001E3* ammoPtr; //0x0014

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0018

class N000001F6
{
public:
	int32_t WeaponAmmo; //0x0000
}; //Size: 0x0004

class N000001E3 : public N000001F6
{
public:
}; //Size: 0x0004

class N00000212
{
public:
	char pad_0000[40]; //0x0000
	int32_t N0000021D; //0x0028
	char pad_002C[24]; //0x002C
}; //Size: 0x0044

class weaponInfo
{
public:
	char pad_0000[260]; //0x0000
	int16_t N00000280; //0x0104
	int16_t N00000291; //0x0106
	int16_t N00000281; //0x0108
	int16_t N00000293; //0x010A
	int16_t N00000282; //0x010C
	int16_t N00000295; //0x010E
	int16_t N00000283; //0x0110
	int16_t N00000297; //0x0112
	int16_t spread; //0x0114
	int16_t recoil; //0x0116
	int16_t magSize; //0x0118
	int16_t N0000029B; //0x011A
	int16_t N00000286; //0x011C
	int16_t kickBack; //0x011E
	int16_t recoilbase; //0x0120
	int16_t maxrecoil; //0x0122
	int16_t pushFactor; //0x0124
	bool isauto; //0x0126
	char pad_0127[1]; //0x0127
}; //Size: 0x0128

