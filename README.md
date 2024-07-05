# KillProgramFromName

This program is a personal exercise in C designed to terminate a program by searching for its name in Linux. It provides two options for matching:

-NP: Matches the program name directly. For example, "terminal" does not match "xfce4-terminal" directly, but matches only "terminal".

-P: Matches by prefix. For example, "terminal" matches "xfce4-terminal" because "terminal" is a substring within "xfce4-terminal".

