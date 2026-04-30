# System Monitor in C

A Linux system monitoring tool written in C.

This project exists to learn Linux fundamentals by building a system monitor from scratch. It reads system information directly from Linux interfaces like `/proc`, `/etc/passwd`, `/var/log`, and system calls instead of relying on existing monitoring tools.

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
- Logs
- Environment variables
- `systemd`
- Cron jobs
- Package management
- Terminal UI with `ncurses`

## Tech Stack

- C
- Linux / Ubuntu Server
- `/proc` filesystem
- POSIX system calls
- `ncurses`
- `systemd`
- Makefile

## Infrastructure

**Development:** macOS, Neovim, TMUX, Ghostty, SSH

**Deployment:** Runs on a self-hosted Ubuntu Server (hostname: star-platinum) deployed on repurposed hardware, accessed via SSH from macOS. No cloud providers — bare metal homelab for hands-on Linux experience.

## Features

Planned features:

- List running processes
- Display process PID, name, status, and memory usage
- Send signals to processes by PID
- List users and match processes to users
- Inspect file permissions and metadata
- Scan directories and show file sizes/inodes
- Monitor CPU usage
- Monitor memory usage
- Monitor disk usage
- Alert when disk usage is above 80%
- List open ports and active TCP connections
- Read and parse system logs
- Write structured application logs
- Rotate and compress log files
- Read configuration from environment variables
- Run as a `systemd` service
- Generate daily reports with cron
- Provide an interactive terminal UI with `ncurses`

## Roadmap
- [ ] Week 1: Process monitoring with /proc
- [ ] Week 2: Users, permissions, and filesystem
- [ ] Week 3: CPU, memory, and disk monitoring
- [ ] Week 4: Networking and SSH
- [ ] Week 5: Logs, compression, and environment variables
- [ ] Week 6: `Systemd`, cron, and package management
- [ ] Week 7: Terminal UI with `ncurses`
- [ ] Week 8: Polish, documentation, and deployment
