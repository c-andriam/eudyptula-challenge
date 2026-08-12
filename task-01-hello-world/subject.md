# Eudyptula Challenge — Task 01

**Source:** Archive communautaire (iomonad/eudyptula), sujet original du challenge officiel eudyptula-challenge.org (aujourd'hui n'accepte plus de nouveaux inscrits).

---

## Sujet original (texte intégral)

> This is Task 01 of the Eudyptula Challenge
>
> Write a Linux kernel module, and stand-alone Makefile, that when loaded
> prints to the kernel debug log level, "Hello World!" Be sure to make
> the module be able to be unloaded as well.
>
> The Makefile should build the kernel module against the source for the
> currently running kernel, or, use an environment variable to specify
> what kernel tree to build it against.
>
> Please show proof of this module being built, and running, in your
> kernel. What this proof is is up to you, I'm sure you can come up with
> something. Also be sure to send the kernel module you wrote, along with
> the Makefile you created to build the module.
>
> Remember to use your ID assigned to you in the Subject: line when
> responding to this task, so that I can figure out who to attribute it
> to. You can just respond to the task with the answers and all should be
> fine.

---

## Traduction / reformulation (pour référence rapide)

Écrire :
1. Un **module noyau Linux** qui, une fois chargé, affiche `"Hello World!"` au **niveau debug** du log noyau.
2. Un **Makefile autonome** capable de :
   - compiler le module contre les sources du **kernel actuellement en cours d'exécution**, OU
   - permettre de spécifier un **arbre kernel différent** via une variable d'environnement.
3. Le module doit pouvoir être **déchargé** proprement.
4. Fournir une **preuve** que le module compile et fonctionne (forme libre — capture dmesg, script, etc.)

---

## Checklist de validation personnelle

- [ ] Le module compile sans erreur ni warning
- [ ] `insmod` charge le module sans erreur
- [ ] `dmesg` affiche "Hello World!" au niveau debug après le chargement
- [ ] `rmmod` décharge le module sans erreur
- [ ] Le Makefile fonctionne avec le kernel actif (`uname -r`) sans modification
- [ ] Le Makefile permet de surcharger l'arbre kernel cible via une variable d'environnement (ex: `KDIR`)
- [ ] `modinfo` affiche correctement license/author/description