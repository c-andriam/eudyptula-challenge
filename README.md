# Eudyptula Challenge

> Solutions et notes d'apprentissage pour l'**Eudyptula Challenge** — une série d'exercices de programmation noyau Linux, partant d'un simple module "Hello World" jusqu'à la soumission de patchs acceptés dans l'arbre source officiel du noyau Linux.

## À propos du challenge

L'Eudyptula Challenge était un programme d'exercices envoyés par email, créé pour permettre à quiconque d'apprendre le développement noyau Linux, quel que soit son niveau de départ. Il comportait 20 tâches progressives, couvrant :

- l'écriture de modules noyau
- la compilation et le boot d'un kernel personnalisé
- les conventions de style de code du noyau
- les interfaces noyau/espace utilisateur (misc devices, debugfs, sysfs)
- la soumission de patchs à la communauté kernel
- les structures de données internes du noyau (listes chaînées, slab allocators)
- l'écriture d'un syscall
- l'analyse statique de code (sparse)
- les threads noyau et files d'attente
- le netfilter (filtrage réseau)
- les ioctls sur système de fichiers

**Note :** le challenge officiel (eudyptula-challenge.org) n'accepte plus de nouvelles inscriptions depuis un moment, après avoir accueilli plus de 19 000 développeurs. Ce dépôt suit les sujets archivés par la communauté, en autodidacte, sans validation officielle par email.

## Contexte personnel

Ce dépôt documente ma progression dans l'apprentissage du développement noyau Linux, en complément de mes projets ft_linux, DromOS Linux (LFS/BLFS) et du projet BADASS (réseaux BGP/VXLAN/EVPN).

Chaque tâche est documentée en détail : pas seulement le code final, mais le raisonnement, les erreurs rencontrées, et les ressources utilisées pour comprendre chaque concept avant de l'implémenter.

## Environnement de développement

- **Distribution hôte :** Fedora (poste principal), DromOS Linux (LFS custom)
- **Kernel de test :** 6.13.4-candriam (custom, compilé depuis les sources)
- **Outils :** GCC, make, git, QEMU/VirtualBox/vagrant pour les tests isolés
- **Documentation kernel de référence :** `Documentation/process/`, `Documentation/kbuild/` dans l'arbre source du noyau lui-même

## Progression

| # | Tâche | Sujet | Statut |
|---|-------|-------|--------|
| 01 | [Hello World Kernel Module](./task-01-hello-world) | Module noyau minimal, chargeable/déchargeable | 🔄 En cours |
| 02 | Building kernel from source | Compilation et boot d'un kernel personnalisé | ⬜ À faire |
| 03 | Tweaking `EXTRAVERSION` | Modification de la chaîne de version + patch | ⬜ À faire |
| 04 | Kernel coding style | Mise en conformité avec les conventions de style kernel | ⬜ À faire |
| 05 | Simple USB event monitor | Chargement automatique via hotplug (USB keyboard) | ⬜ À faire |
| 06 | Simple Char Device | Misc char device driver, lecture/écriture | ⬜ À faire |
| 07 | Working with `linux-next` | Compilation et boot du kernel de développement | ⬜ À faire |
| 08 | Working with DebugFS | Fichiers virtuels debugfs (id, jiffies, foo) | ⬜ À faire |
| 09 | Working with SysFS | Migration debugfs → sysfs, kobjects | ⬜ À faire |
| 10 | Submitting patches | Premier patch envoyé à la communauté kernel | ⬜ À faire |
| 11 | Patch sur module en cours d'exécution | Ajout de fichier sysfs sur un driver réel | ⬜ À faire |
| 12 | Kernel Linked List | Implémentation avec `struct list_head` | ⬜ À faire |
| 13 | `kmem_cache` slab allocator | Allocation mémoire via cache dédié | ⬜ À faire |
| 14 | Hacking `task_struct` | Ajout de champ custom + fichier `/proc/PID/` | ⬜ À faire |
| 15 | Implémenter un syscall | Nouveau syscall + programme userspace de test | ⬜ À faire |
| 16 | Analyse statique (SPARSE) | Détection et correction de bug via sparse | ⬜ À faire |
| 17 | `kthreads` & Wait queues | Thread noyau + file d'attente | ⬜ À faire |
| 18 | Blocking & delegating workload | Traitement différé avec liste + thread | ⬜ À faire |
| 19 | Module `netfilter` | Filtrage de paquets IPv4, détection de motif | ⬜ À faire |
| 20 | IOCTL sur FAT(32) | Modification du label de volume via ioctl custom | ⬜ À faire |

## Structure du dépôt

```
eudyptula-challenge/
├── README.md                        # ce fichier
│
├── task-01-hello-world/
│   ├── hello.c
│   ├── Makefile
│   └── NOTES.md                     # explications, preuves, captures dmesg
│
├── task-02-custom-kernel/
│   ├── config-eudyptula             # .config utilisé pour le build
│   └── NOTES.md                     # étapes de build, preuve de boot
│
├── task-03-extraversion/
│   ├── 0001-extraversion.patch
│   └── NOTES.md
│
├── task-04-coding-style/
│   ├── module-a-fixed.c
│   ├── module-b-fixed.c
│   └── NOTES.md                     # diff avant/après, sortie checkpatch.pl
│
├── task-05-usb-hotplug/
│   ├── hello_usb.c
│   ├── Makefile
│   └── NOTES.md
│
├── task-06-misc-chardev/
│   ├── misc_dev.c
│   ├── Makefile
│   └── NOTES.md
│
├── task-07-linux-next/
│   └── NOTES.md                     # pas de code, juste build + preuve de boot
│
├── task-08-debugfs/
│   ├── debugfs_mod.c
│   ├── Makefile
│   └── NOTES.md
│
├── task-09-sysfs/
│   ├── sysfs_mod.c
│   ├── Makefile
│   └── NOTES.md
│
├── task-10-first-patch/
│   ├── 0001-staging-fix.patch
│   └── NOTES.md                     # lien vers l'archive de la mailing list
│
├── task-11-driver-sysfs/
│   ├── 0001-driver-add-id-sysfs.patch
│   └── NOTES.md
│
├── task-12-linked-list/
│   ├── identity_list.c
│   ├── Makefile
│   └── NOTES.md
│
├── task-13-slab-cache/
│   ├── 0001-use-kmem-cache.patch    # diff par rapport à task-12
│   └── NOTES.md                     # sortie /proc/slabinfo
│
├── task-14-task-struct/
│   ├── 0001-add-id-field-task-struct.patch
│   └── NOTES.md
│
├── task-15-syscall/
│   ├── 0001-add-sys-eudyptula.patch
│   ├── test_syscall.c               # programme userspace
│   └── NOTES.md
│
├── task-16-sparse/
│   ├── 0001-staging-fix-sparse-warning.patch
│   └── NOTES.md
│
├── task-17-kthread/
│   ├── kthread_mod.c
│   ├── Makefile
│   └── NOTES.md
│
├── task-18-workqueue/
│   ├── workqueue_mod.c
│   ├── Makefile
│   └── NOTES.md
│
├── task-19-netfilter/
│   ├── netfilter_mod.c
│   ├── Makefile
│   └── NOTES.md
│
└── task-20-fat-ioctl/
    ├── 0001-fat-add-label-ioctl.patch
    ├── test_ioctl.c                 # programme userspace
    └── NOTES.md
```

Chaque dossier de tâche contient :
- le code source (module, patch, programme userspace selon la tâche)
- un `NOTES.md` documentant la démarche, les difficultés rencontrées, et la preuve de fonctionnement
- le Makefile si applicable

## Ressources de référence générales

- *Linux Device Drivers, 3rd Edition* (LDD3) — gratuit, référence historique pour l'écriture de drivers
- `Documentation/process/coding-style.rst` — style de code officiel du noyau
- `Documentation/process/submitting-patches.rst` — procédure de soumission de patchs
- `Documentation/kbuild/modules.rst` — écriture de Makefiles pour modules externes
- Archives communautaires du challenge : [iomonad/eudyptula](https://github.com/iomonad/eudyptula)

## Licence

Le code de ce dépôt est publié sous licence [Unlicense](https://unlicense.org/) / domaine public, sauf mention contraire dans un dossier spécifique (les patchs soumis au noyau suivent la licence GPL du kernel).