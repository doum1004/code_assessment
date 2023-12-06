import os

def sum_calibration_values(input_text):
    total_sum = 0

    # Iterate through each line in the input
    #log = ''
    for line in input_text.split('\n'):
        # Extract digits from the line
        digits = [char for char in line if char.isdigit()]

        # If there are at least two digits, form a two-digit number and add to the sum
        if len(digits) >= 1:
            two_digit_number = 0
            two_digit_number = int(digits[0] + digits[-1])
            total_sum += two_digit_number
            #log += f"{two_digit_number} "
    #print(log)

    return total_sum

# intput from cur folder/'input.txt'
input_text_path = 'input.txt'
cur_folder = os.path.dirname(os.path.abspath(__file__))

input_text = ''
with open(os.path.join(cur_folder, input_text_path), 'r') as f:
    input_text = f.read()

# Calculate and print the sum
result = sum_calibration_values(input_text)
print(f"The sum of calibration values is: {result}")