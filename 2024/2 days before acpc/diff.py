def compare_files(file1, file2, file3):
    with open(file1, 'r') as f1, open(file2, 'r') as f2, open(file3, 'r') as f3:
        lines1 = f1.readlines()
        lines2 = f2.readlines()
        lines3 = f3.readlines()

    differences = []
    max_lines = max(len(lines1), len(lines2))

    for i in range(max_lines):
        line1 = lines1[i] if i < len(lines1) else None
        line2 = lines2[i] if i < len(lines2) else None
        line3 = lines3[i] if i < len(lines3) else None

        if line1 != line2:
            differences.append((i + 1, line1, line2, line3))  # Store line number and differing lines

    return differences


def print_differences(differences, file1, file2, file3):
    if differences:
        for line_num, line1, line2, line3 in differences:
            print(f"Line {line_num}:")
            print(f"{file1}: {line1.strip() if line1 else 'No line'}")
            print(f"{file2}: {line2.strip() if line2 else 'No line'}")
            print(f"{file3}: {line3.strip() if line3 else 'No line'}")
            print('-' * 40)
    else:
        print("The files are identical.")


if __name__ == "__main__":
    file1 = 'test_output.txt'  # Replace with your first file path
    file2 = 'user_output.txt'  # Replace with your second file path
    file3 = 'test_input.txt'  # Replace with your third file path

    differences = compare_files(file1, file2, file3)
    print_differences(differences, file1, file2, file3)
