 switch (fr)
  {
    case FillRule::EvenOdd: fillrule_string = "EVENODD"; break;
    case FillRule::NonZero: fillrule_string = "NONZERO"; break;
    case FillRule::Positive: fillrule_string = "POSITIVE"; break;
    case FillRule::Negative: fillrule_string = "NEGATIVE"; break;
  }

  source << "CAPTION: " << last_test_no <<"." << endl;
  source << "CLIPTYPE: " << cliptype_string << endl;
  source << "FILLRULE: " << fillrule_string << endl;
  source << "SOL_AREA: " << area << endl;
  source << "SOL_COUNT: " << count << endl;
  if (subj)
  {
    source << "SUBJECTS" << endl;
    PathsToStream(*subj, source);
  }
  if (subj_open)
  {
    source << "SUBJECTS_OPEN" << endl;
    PathsToStream(*subj_open, source);
  }
  if (clip && clip->size())
  {
    source << "CLIPS" << endl;
    PathsToStream(*clip, source);
  }
  source << endl;
  source.close();
  return true;
}
