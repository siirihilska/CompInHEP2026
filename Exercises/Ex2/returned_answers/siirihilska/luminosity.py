import re

with open("brilcalc.log") as file:
	contents = file.read()
	
# First, we'll find the column name row that matches totrecorded	
find_column = re.search(r"\|.*totrecorded\(/pb\).*?\|", contents)
column_row = find_column.group(0)

# Turning the column names to a list so that we can find the index and then match the data value index to it
column_names = [name.strip() for name in column_row.strip("|").split("|")]

index = column_names.index("totrecorded(/pb)")

# Then, finding the numerical values from the file after the column name row
find_values = re.search(r"^\|.*\d.*\|$", contents[find_column.end():], re.MULTILINE)
value_row = find_values.group(0)

values = [value.strip() for value in value_row.strip("|").split("|")]

# Locating the value based on the index
luminosity_pb = float(values[index])
luminosity_fb = luminosity_pb / 1000

print(f"{luminosity_fb:.1f} fb^-1")
