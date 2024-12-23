def main():
    import json

    file = open('data.json', 'r')

    trains = json.load(file)

    file.close()

    train = {
        input('Date (yyyy-mm-dd): ') : {
            'from' : input('From (station code): ').upper(),
            'to' : input('To (station code): ').upper(),
            'change' : 'direct' if not (raw := input('Change (comma seperated station code(s), default is none): ')) else raw.upper().split(','),
            'trans' : raw.split(',') if ',' in (raw := input('Journey(s) (comma seperated): ')) else raw
        }
    }

    print()
    print(train)

    if 'y' in input('Does this look right?: '):
        trains |= train

        file = open('data.json', 'w')

        json.dump(trains, file)

        file.close()

if __name__ == '__main__':
    main()
