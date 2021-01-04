# Author:   Rachael Judy
# Date:     1/3/2021
# Purpose:  script to convert decimal intcode input to hexadecimal RAM program for intcode computer in logisim

import csv
import sys

dec_filename = sys.argv[1]
if dec_filename == '-h':
    print('Usage: python intcode_to_hex.py <decimal_input_filename> <hex_output_filename>')
    exit(0)
hex_filename = sys.argv[2] if len(dec_filename) == 3 else 'hex_program'


def readCSV(filename, delim=','):
    with open(filename) as file:
        reader = csv.reader(file, delimiter=delim)
        for row in reader:  # single row
            num = [int(s) for s in row]
    return num


hex_array = [str(hex(number & (2**32-1)))[2:] for number in readCSV(dec_filename)]

f = open(hex_filename, 'w')
f.write('v2.0 raw\n' + ' '.join(hex_array))
f.close()