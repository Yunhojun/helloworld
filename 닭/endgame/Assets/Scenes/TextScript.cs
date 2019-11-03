using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TextScript : MonoBehaviour
{
    public Text text;
    int score;
    GameObject Manager;
    // Start is called before the first frame update
    void Start()
    {
        Manager = GameObject.FindGameObjectWithTag("GameController");
        score = 0;
        text.text = "SCORE: " + score;
    }

    // Update is called once per frame
    void Update()
    {
        score = Manager.GetComponent<CreaterScript>().score;
        text.text = "SCORE: " + score;
    }
}
