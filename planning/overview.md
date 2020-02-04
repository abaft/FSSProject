author: Benjamin Chalmers
title: FSMS: Finite State Machine Solver
subtitle: Scoping and Planning
---

# Scope

This Section will detail the scope of this project, the deliverables, and what benefit these features will provide the user.

## User friendly input system for a finite state machine

Provided to the user will be a user friendly input system, which will allow the user to specify any (within reasonable limits) finite state machine (that is: the 5 element tuple $(Q,\Sigma,\delta, q_0, F)$  with user readable labels).

This will benefit the user in creating a way to interface with my program in an intuitive and easy way, saving them time.
The user will also be able to export this to a file and share it with others.

## Output viewer

A viewer to see the produced logic circuit.

This provides the user with a nice visual overview of the state machine, and allows the user to present this (will be exportable as an svg oe).

## Output to hdl

This will give the user an hdl file, which can then be used to program an FPGA or produce an ASIC.
Or it can be used in another program to simulate the function of the finite state machine.

## Minimisation/optimisation

This part will take an abstract finite state machine and output a logic circuit in primitive logical block.
My boolean bases are yet to be determined.

# Steak Holders

## Engineers

These are likely the users of my software

# Plan

## Research phase

In the research phase I intend to discover the best way to implement the 4 deliverables laid out in my scope.
The research will be documented the next chapter of this document, and will lend to a deeper understanding of how long each section will take.

## My estimation

From a cursory look at the problem I suspect that the major challenges I will have will be:

1. Creating a data structure to efficiently parse and store finite state machine schema.
2. Performing pre-minimisation/optimisation on the FSM.
3. Finding algorithms to minimise boolean expressions.

These are the problems which appear to be the most tricky to solve.

# Resarch
