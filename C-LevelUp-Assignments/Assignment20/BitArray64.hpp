#pragma once

class BitArray64
{
public:
	BitArray64() = default;
	BitArray64(const BitArray64&) = default;
	BitArray64& operator=(const BitArray64&) = default;

	bool operator==(const BitArray64& rhs) const;
	bool operator!=(const BitArray64& rhs) const;

	int Get();
	void Return(int index);
	void Set(int index, bool value);
	bool Value(int index);

	static constexpr int kArraySize = 64;

private:
	unsigned long long mBits;
	unsigned long long mBitsInUse;
};