import os

def sum_calibration_values(input_text):
    total_sum = 0

    # Iterate through each line in the input
    spelled_out_to_digit = {'one': '1', 'two': '2', 'three': '3', 'four': '4', 'five': '5',
                        'six': '6', 'seven': '7', 'eight': '8', 'nine': '9'}

    log = ''
    for line in input_text.split('\n'):
        # Extract all digits (including spelled-out numbers) from the line
        digits = []
        
        # get first and last str digit or actual digit
        # ex1) zoneight234. 1(one), 2 3 4
        # ex2) eightwothree. 8(eight) 3(three)
               
        for i in range(len(line)):
            if line[i].isdigit():
                digits.append(line[i])
            elif line[i].isalpha():
                word = ''
                for j in spelled_out_to_digit:
                    if line[i:].startswith(j):
                        word = j
                        break
                if word:
                    digits.append(spelled_out_to_digit[word])
                    i += len(word) - 1
                

        # Remove empty strings from the list
        digits = [char for char in digits if char]

        # If there are at least two digits, form a two-digit number and add to the sum
        if len(digits) >= 1:
            two_digit_number = 0
            two_digit_number = int(digits[0] + digits[-1])
            total_sum += two_digit_number
            log += f"{two_digit_number} "
    print(log)

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