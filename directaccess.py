import os

# Define the size of each record in bytes
RECORD_SIZE = 64

def create_file(file_name, num_records):
    # Create a new file with the specified number of records
    with open(file_name, 'wb') as file:
        file.seek(RECORD_SIZE * (num_records - 1))
        file.write(b'\0')

def write_record(file_name, record_number, data):
    # Write the data to the specified record number
    with open(file_name, 'r+b') as file:
        file.seek(RECORD_SIZE * record_number)
        file.write(data.encode())

def read_record(file_name, record_number):
    # Read the data from the specified record number
    with open(file_name, 'rb') as file:
        file.seek(RECORD_SIZE * record_number)
        data = file.read(RECORD_SIZE).decode().rstrip('\0')
        return data


def delete_file(file_name):
    # Delete the file from the filesystem
    os.remove(file_name)
    print(f"File '{file_name}' deleted.")

# Usage example
filename = 'data.bin'
num_records = 5

create_file(filename, num_records)

# Write records

write_record(filename, 0, 'John Doe')
write_record(filename, 1, 'Jane Smith')
write_record(filename, 2, 'Alice Johnson')

# Read records
print(read_record(filename, 0))  # Output: John Doe
print(read_record(filename, 1))  # Output: Jane Smith
print(read_record(filename, 2))  # Output: Alice Johnson

# Delete the file
delete_file(filename)
