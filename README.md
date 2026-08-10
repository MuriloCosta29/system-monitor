# System Monitor in C

A Linux system monitoring tool written in C.

This project exists to learn Linux fundamentals by building a system monitor from scratch. It reads system information directly from Linux interfaces like `/proc`, `/etc/passwd`, and system calls instead of relying on existing monitoring tools.

## Goal

Build a terminal-based system monitor that runs on Ubuntu Server and helps understand how Linux works under the hood.

The project focuses on learning:

- Processes
- Signals
- Users and groups
- File permissions
- Filesystem metadata
- CPU usage
- Memory usage
- Disk usage
- Network connections

## Tech Stack

- C
- Linux / Ubuntu Server
- `/proc` filesystem
- POSIX system calls
- `systemd` (deployment only)
- Makefile

## Infrastructure

**Development:** macOS, Neovim, TMUX, Ghostty, SSH

**Deployment:** Runs on a self-hosted Ubuntu Server (hostname: star-platinum) deployed on repurposed hardware, accessed via SSH from macOS. No cloud providers — bare metal homelab for hands-on Linux experience.

## Features

Items marked ❌ were deliberately dropped. The reasoning is in **Out of scope**.

- List running processes
- Display process PID, name, status, and memory usage
- Send signals to processes by PID
- List users and match processes to users
- Inspect file permissions and metadata
- Scan directories and show file sizes
- Monitor CPU usage
- Monitor memory usage
- Monitor disk usage, including free inodes
- Alert when disk usage is above 80%
- List open ports and active TCP connections
- Run as a `systemd` service — kept, but as a deployment step, not a feature
- Read and parse system logs ❌
- Write structured application logs ❌
- Rotate and compress log files ❌
- Read configuration from environment variables ❌
- Generate daily reports with cron ❌
- Provide an interactive terminal UI with `ncurses` ❌

## Roadmap

Scope is closed. Anything not listed here is in **Out of scope**, below.

- [ ] **1. Processes** — walk `/proc` for numeric directories; read PID, name, state and memory; map UID to username through `/etc/passwd`; send signals by PID.
- [ ] **2. Files and permissions** — metadata with `stat()`; scan a directory and list the largest files.
- [ ] **3. Resources** — CPU from `/proc/stat` deltas between two samples; memory from `/proc/meminfo`; disk from `statvfs()`, including free inodes; warn above 80% usage.
- [ ] **4. Network** — listening ports and TCP connection states from `/proc/net/tcp`.
- [ ] **5. Finish** — README, build instructions, and a `systemd` unit so it runs on the server.

No dates on purpose: this is study time, not a sprint. A milestone is either done or it isn't.

## Out of scope (and why)

This project exists to read the system directly — `/proc`, `/etc/passwd`, syscalls. Everything below was cut on purpose, not left behind.

**Interactive terminal UI with `ncurses`**
A TUI is presentation code. It would teach me a library and nothing about the kernel, which is the whole point here. Plain `stdout` prints the same numbers.

**Reading and parsing system logs**
On current Ubuntu the system log lives in journald, in a binary format. I'd either parse text files that barely exist anymore, or integrate `libsystemd` — library integration, not systems fundamentals. The part actually worth learning (`journalctl -u`, `-p`, `--since`) I get from the terminal for free.

**Writing structured application logs**
The modern convention is that a program writes to `stdout` and does not manage its own logs; whatever collects them — journald, Docker, an aggregator — takes it from there. Learning that means deliberately *not* implementing it. It's the one cut where the knowledge shows up as one less line of code.

**Rotating and compressing log files**
Reimplementing `logrotate` teaches file handling in C, not `/proc`. It also contradicts the item above: if the program doesn't own its logs, it doesn't rotate them either.

**Reading configuration from environment variables**
It's `getenv()`. If I need a configurable sampling interval I'll add one, but a single call isn't a feature.

**Generating daily reports with cron**
Crontab syntax, not a concept. And if the tool already runs continuously, a daily report is redundant.

**Package management**
Unrelated to monitoring. It was on the list because I wanted to learn it, not because the tool needed it — and I already practise it keeping this server alive.

One more thing, since honesty is the point of this section. Not every decision here is a cold calculation about what I'll learn — sometimes I build something simply because I enjoy building it. I do like `ncurses`. Cutting it isn't me pretending otherwise; it's me admitting this isn't the moment. I need to finish this project to start the next one, and the next one is backend, which is what my career needs right now.

### Not cut, just not code

Running as a `systemd` service is still the plan. But a unit file is eight lines written in twenty minutes at the end, not a milestone: it belongs in the deployment instructions, not in the roadmap. The C code doesn't change either way.

### Why this section exists

A missing feature reads as *didn't manage to*. A cut feature with a reason reads as a decision. Writing the reasons down is also how I stop myself from quietly adding them back later.
