import random
import string

def generate_random_integer():
    return random.randint(100000, 999999)

def generate_random_string_with_whitespace():
    letters_and_digits = string.ascii_letters + string.digits
    random_position = random.randint(0, 14)
    random_string = ''.join(random.choice(letters_and_digits) for _ in range(14))
    random_string = random_string[:random_position] + ' ' + random_string[random_position:]
    return random_string

def generate_random_integer_1_or_2():
    return random.choice([1, 2])

def generate_random_money():
    return round(random.uniform(1.0, 1000.0), 6)

def generate_test_data(num_datasets, entries_per_dataset, filename):
    with open(filename, 'w') as file:
        for dataset in range(num_datasets):
            for _ in range(entries_per_dataset):
                entry = [
                    str(generate_random_integer()),
                    generate_random_string_with_whitespace(),
                    str(generate_random_integer_1_or_2()),
                    str(generate_random_money())
                ]
                file.write('\n'.join(entry) + '\n')  # Separate data elements by newlines
            ##if dataset < num_datasets - 1:
            ##    file.write('\n')  # Separate datasets by newlines
        ##file.write('0\n')

if __name__ == "__main__":
    num_datasets = 50  # Number of datasets
    entries_per_dataset = 1  # Number of entries per dataset
    filename = "test_data.txt"  # Change this to your desired file name
    generate_test_data(num_datasets, entries_per_dataset, filename)
    print(f"{num_datasets} datasets with {entries_per_dataset} entry each generated and saved in '{filename}'.")
