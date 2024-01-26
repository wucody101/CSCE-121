// TODO: Implement this header file
# ifndef STRING_H
# define STRING_H
# include <iostream>

class MyString {
	private:
		char* string;
        size_t sizenum;
        size_t capacitynum;
        friend std::ostream& operator<<(std::ostream& os, const MyString& string);
        friend bool operator==(const MyString& lhs, const MyString& rhs) noexcept;
        friend MyString operator+(const MyString& lhs, const MyString& rhs);
	public:
		// constructors
        MyString();
        MyString(const MyString& copy);
        MyString(const char* copy);

        // destructors
        ~MyString();

		// getters
        size_t capacity() const noexcept;
        size_t size() const noexcept;
        size_t length() const noexcept;
        const char* data() const noexcept;
        bool empty() const noexcept;
        const char& front() const;
        const char& at(size_t pos) const;
        size_t find(const MyString& string, size_t pos = 0) const noexcept;

		// setters
        MyString& operator=(const MyString& copy);
        MyString& operator+=(const MyString& add);

		// member functions
        void resize(size_t n);
        void clear() noexcept;
		
};

# endif
