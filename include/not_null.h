#include <type_traits>

template <typename P>
class not_null {

	static_assert(std::is_pointer<P>::value, "This template can only be instantiated with a pointer type");

	public:
		not_null(P ptr) : ptr_(ptr) { }

		template <typename FromType>
		not_null(FromType f) {
			static_assert(std::is_convertible<FromType, P>::value, "Cannot convert type to required pointer type");
			ptr_ = f;
		}

		not_null(int) = delete;
		not_null(std::nullptr_t) = delete;

		P get() const { return ptr_; }
		decltype(*P()) operator *() const { return *ptr_; }

	private:
		P ptr_;
};
