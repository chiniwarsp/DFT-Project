import ctypes

# Load the shared library
lib = ctypes.CDLL("./libpi.so")

# Declare argument types
lib.compute_pi.argtypes = [ctypes.c_char_p, ctypes.c_int]


def get_pi(digits=20):
    buf = ctypes.create_string_buffer(1024)
    lib.compute_pi(buf, digits)
    return buf.value.decode()


if __name__ == "__main__":
    pi_val = get_pi(20)
    print("Value of pi to 20 decimal digits:")
    print(pi_val)
