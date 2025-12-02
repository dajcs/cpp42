import random

def generate_file(filename='output.txt', lines=1000, chars_per_line=1000,
                  dot_percentage=90, o_percentage=10):
    """
    Generate a file with random '.' and 'o' characters.

    Args:
        filename: Output file name
        lines: Number of lines to generate
        chars_per_line: Number of characters per line
        dot_percentage: Percentage of '.' characters (default 90)
        o_percentage: Percentage of 'o' characters (default 10)
    """
    # Validate percentages
    if dot_percentage + o_percentage != 100:
        print(f"Warning: Percentages sum to {dot_percentage + o_percentage}%, adjusting proportionally")

    # Calculate weights for random.choices
    weights = [dot_percentage, o_percentage]
    characters = ['.', 'o']

    with open(filename, 'w') as f:
        for i in range(lines):
            # Generate a line with weighted random selection
            line = ''.join(random.choices(characters, weights=weights, k=chars_per_line))
            f.write(line + '\n')

            # Print progress every 100 lines
            if (i + 1) % 100 == 0:
                print(f"Generated {i + 1}/{lines} lines...")

    print(f"\nFile '{filename}' generated successfully!")
    print(f"Total lines: {lines}")
    print(f"Characters per line: {chars_per_line}")
    print(f"Approximate distribution: {dot_percentage}% '.', {o_percentage}% 'o'")

if __name__ == "__main__":
    # Generate the file with default settings (90% '.', 10% 'o')
    # generate_file()

    # Example: Generate with different percentages
    generate_file(filename='big_example', dot_percentage=99.9, o_percentage=0.1)
