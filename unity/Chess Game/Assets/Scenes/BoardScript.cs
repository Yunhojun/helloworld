﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoardScript : MonoBehaviour
{
    public bool isOnUnit = false;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerStay(Collider other)
    {
        print("ASDA");
        isOnUnit = true;
    }

    private void OnTriggerExit(Collider other)
    {
        isOnUnit = false;
    }
}
