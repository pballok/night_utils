#include <gtest/gtest.h>
#include <not_null.h>

class A {
public:
	explicit A(int i) : i_(i) {}
	void set(int i) { i_ = i; }
	int get() const { return i_; }

private:
	int i_ = 0;
};

class B : public A {
public:
	explicit B(int i) : A(i) {}
};

TEST(not_null, RawPointerGet) {
	A  a(10);
	not_null<A*> p(&a);

	EXPECT_EQ(10, a.get());

	p.get()->set(42);

	EXPECT_EQ(42, a.get());
}

TEST(not_null, RawPointerDereference) {
	A  a(10);
	not_null<A*> p(&a);

	EXPECT_EQ(10, a.get());

	(*p).set(42);

	EXPECT_EQ(42, a.get());
}

TEST(not_null, RawPointerCompatible) {
	B b(10);

	not_null<A*> p(&b);

	EXPECT_EQ(10, (*p).get());

	(*p).set(42);

	EXPECT_EQ(42, (*p).get());
}
