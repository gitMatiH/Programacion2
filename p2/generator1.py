import random
import string

def generate_random_integer():
    return random.randint(100000, 999999)

def generate_random_string():
    letters_and_digits = string.ascii_letters + string.digits
    return ''.join(random.choice(letters_and_digits) for _ in range(15))

def generate_random_integer_1_or_2():
    return random.choice([1, 2])

def generate_random_money():
    return round(random.uniform(1.0, 1000.0), 6)

def generate_test_data(num_entries, filename):
    with open(filename, 'w') as file:
        for _ in range(num_entries):
            entry = [
                str(generate_random_integer()),
                generate_random_string() + ' ' + generate_random_string(),
                str(generate_random_integer_1_or_2()),
                str(generate_random_money())
            ]
            file.write('\t'.join(entry) + '\n')

if __name__ == "__main__":
    num_entries = 10  # Number of entries you want in the text file
    filename = "test_data.txt"  # Change this to your desired file name
    generate_test_data(num_entries, filename)
    print(f"{num_entries} entries generated and saved in '{filename}'.")
