import os

mapping = {
    'ä': 'ae',
    'ö': 'oe',
    'ü': 'ue',
    'Ä': 'AE',
    'Ö': 'OE',
    'Ü': 'UE'
}

def normalize_filename(filename: str):
    if filename.endswith(".md"):
        return filename

    for umlaut, replacement in mapping.items():
        filename = filename.replace(umlaut, replacement)

    return filename

def replace_umlauts(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            original_path = os.path.join(root, file)
            normalized_name = normalize_filename(file)
            new_path = os.path.join(root, normalized_name)

            if original_path != new_path:
                os.rename(original_path, new_path)
                print(f'Renamed: {original_path} -> {new_path}')

if __name__ == "__main__":
    directory_path = os.getcwd() 
    replace_umlauts(directory_path)
