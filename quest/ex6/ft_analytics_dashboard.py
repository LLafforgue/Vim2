import random

achievments = {
    "monster": {
        "cat": "kill",
        "action": 2
    },
    "ring": {
        "cat": "treasure",
        "action": "inventory"
    },
    "boss": {
        "cat": "kill",
        "action": 5
    },
    "one_level": {
        "cat": "level_up",
        "action": 1
    },
    "sword": {
        "cat": "treasure",
        "action": "inventory"
    }
}

players = {
    "Alice": {
        "level": 5,
        "events": [],
        "inventory": [],
        "score": 28
    },
    "Bob": {
        "level": 1,
        "events": [],
        "inventory": [],
        "score": 2

    },
    "Charlie": {
        "level": 5,
        "events": [],
        "inventory": [],
        "score": 35
    },
    "Sarah": {
        "level": 3,
        "events": [],
        "inventory": [],
        "score": 12
    },
    "Yasmine": {
        "level": 0,
        "events": [],
        "inventory": [],
        "score": 0
    },
    "Will": {
        "level": 9,
        "events": [],
        "inventory": [],
        "score": 68
    }
}


def x_events_rand(nbr: int, achvts: list[str], plys: list[str]):
    """
    Generates random game events for players.

    Args:
    nbr (int): The number of events to generate.
    achvts (list[str]): The list of possible event types.
    plys (list[str]): The list of existing players.

    Yields:
    str: A description of the generated event.
    """
    i = 1
    while i <= nbr:
        ply = random.choice(plys)
        if ply not in players:
            raise KeyError(f"{ply} is not an existing player")
        player = players[ply]
        ach = random.choice(achvts)
        if ach not in achievments:
            raise KeyError(f"{ach} is not an excpected event")
        player["events"].append(achievments[ach]["cat"])
        if achievments[ach]["cat"] == "treasure":
            msg = "found treasure"
            player["inventory"].append(ach)
        if achievments[ach]["cat"] == "level_up":
            msg = "leveled up"
            player["level"] += achievments[ach]["action"]
        if achievments[ach]["cat"] == "kill":
            msg = f"killed a {ach}"
            player["score"] += achievments[ach]["action"]
        event = f"Event {i}: Player {ply} (level {player["level"]}) {msg}"
        i += 1
        yield event


def analytics(total: int) -> None:
    """
    Displays statistics on the processed events.

    Args:
    total (int): The total number of events processed.
    """
    print("Total events processed:", total)
    count = {"level_up": 0, "kill": 0, "treasure": 0}
    for ply in players:
        for event in players[ply]["events"]:
            count[event] += 1
    high_level = sum(1 for g in players if players[g]["level"] > 10)
    print(f"High-level players (10+): {high_level}")
    print(f"Treasure events: {count['treasure']}")
    print(f"Level-up events: {count['level_up']}")


high_score_players = [ply for ply in players if players[ply]["score"] > 50]
print("High score players (score > 50):", high_score_players)

score_avg = sum(players[ply]["score"] for ply in players) / len(players)
score_categories = {
    "low": sum(1 for ply in players if players[ply]["score"] < score_avg),
    "medium": sum(1 for ply in players if players[ply]["score"] == score_avg),
    "high": sum(1 for ply in players if players[ply]["score"] >= score_avg)
}
print("Score categories based on average score:")
print(f"Low score players: {score_categories['low']}")
print(f"Medium score players: {score_categories['medium']}")
print(f"High score players: {score_categories['high']}")
